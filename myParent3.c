#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char * argv[]){
	char * splitter = (char *)malloc(sizeof(char)*20);
	char * sorter = (char *)malloc(sizeof(char)*20);
	char * merger = (char *)malloc(sizeof(char)*20);
	char * datafile = (char *)malloc(sizeof(char)*20);	
	char * size = (char *)malloc(sizeof(char)*20);
	char * seg1 = (char *)malloc(sizeof(char)*10);
	char * seg2 = (char *)malloc(sizeof(char)*10);
//User Prompt
	printf("Enter filename of splitting program: ");
	scanf("%s", splitter);
	printf("Enter filename of sorting program: ");
	scanf("%s", sorter);
	printf("Enter filename of merging program: ");
	scanf("%s", merger);
	printf("Enter filename of the data file: ");
	scanf("%s", datafile);
	printf("Enter number of strings to sort: ");
	scanf("%s", size); 
	int nStr = atoi(size);
	int part1 = nStr / 2;
	int part2 = nStr - part1;
	sprintf(seg1, "%d", part1);
	sprintf(seg2, "%d", part2);
	printf("seg1: %s\n", seg1);
	printf("seg2: %s\n", seg2);
//Pipe it up
	int pipe1[2];
	int pipe2[2];
	int pipe3[2];
	int pipe4[2];
	int pipe5[2];
	if(pipe(pipe1) < 0)
		printf("Pipe 1 Error\n");
	if(pipe(pipe2) < 0)
		printf("Pipe 2 Error\n");
	if(pipe(pipe3) < 0)
		printf("Pipe 3 Error\n");
	if(pipe(pipe4) < 0)
		printf("Pipe 4 Error\n");
	if(pipe(pipe5) < 0)
		printf("Pipe 5 Error\n");
//FormatFile
//	int fd5 = open("pipe5.txt", O_RDWR | O_CREAT);
//Fork1
	pid_t pid1 = fork();
	if(pid1 < 0){
		printf("Fork 1 Failed\n");
		exit(-1);
	}	
	if(pid1 > 0){		//Parent Process
		pid_t pid2 = fork();
		if(pid2 < 0){
			printf("Fork 2 Failed\n");
			exit(-1);
		}
		if(pid2 > 0){		//Parent Continued
			pid_t pid3 = fork();
			if(pid3 < 0){
				printf("Fork 3 Failed\n");
				exit(-1);
			}
			if(pid3 > 0){		//Parent Continued
				pid_t pid4 = fork();
				if(pid4 < 0){
					printf("Fork 4 Failed\n");
					exit(-1);
				}
				if(pid4 > 0){		//Parent Continued
					pid_t pid5 = fork();
					if(pid5 < 0){
						printf("Fork 5 Failed\n");
						exit(-1);
					}
					if(pid5 > 0){		//Parent Continued
						pid_t pid6 = fork();
						if(pid6 < 0){
							printf("Fork 6 Failed\n");
							exit(-1);
						}
						if(pid6 > 0){		//Parent Continued
							pid_t pid7 = fork();
							if(pid7 < 0){
								printf("Fork 7 Failed\n");
								exit(-1);
							}
							if(pid7 > 0){		//Parent Last
								printf("LAST PARENT PROCESS\n");
								wait(pid7);
								exit(0);
							}
							else if(pid7 == 0){	//Child 7: myCat 1
								printf("CHILD PROCESS 7\n");
								close(pipe1[0]);
								close(STDOUT_FILENO);
								dup2(pipe1[1], STDOUT_FILENO);
								int ret = execlp(splitter, splitter, datafile, "0", seg1, NULL);
								if(ret == -1){
									printf("myCat 1 Failed to execute\n");
								}
								exit(0);
							}
						}
						else if(pid6 == 0){	//Child 6: myCat 2
							printf("CHILD PROCESS 6\n");
							close(pipe2[0]);
							close(STDOUT_FILENO);
							dup2(pipe2[1], STDOUT_FILENO);
							int ret2 = execlp(splitter, splitter, datafile, seg1, size, NULL);
							if(ret2 == -1) printf("myCat 2 Failed to execute\n"); 
							exit(0);
						}
					}
					else if(pid5 == 0){	//Child 5: mySort 1
						printf("CHILD PROCESS 5\n");
						close(pipe1[1]);
						close(STDIN_FILENO);
						close(pipe3[0]);
						close(STDOUT_FILENO);
						dup2(pipe3[1], STDOUT_FILENO);
						dup2(pipe1[0], STDIN_FILENO);
						int s1 = execlp(sorter, sorter, NULL);
						if(s1 == -1){
							printf("mySort 1 Failed to execute\n");
						}
						exit(0);
					}
					close(pipe3[1]);
					close(pipe3[0]);
				}
				else if(pid4 == 0){	//Child 4: mySort 2
					printf("CHILD PROCESS 4\n");
					close(pipe2[1]);
					close(STDIN_FILENO);
					close(pipe4[0]);
					close(STDOUT_FILENO);
					dup2(pipe4[1], STDOUT_FILENO);
					dup2(pipe2[0], STDIN_FILENO);
					int s2 = execlp(sorter, sorter, NULL);
					if(s2 == -1) printf("mySort 2 Failed to execute\n");
					exit(0);
				}
				close(pipe4[0]);
				close(pipe4[1]);
			}
			else if(pid3 == 0){	//Child 3: myFormat 1
				printf("CHILD PROCESS 3\n");
				close(pipe3[1]);
				close(STDIN_FILENO);
				close(pipe5[0]);
				close(STDOUT_FILENO);
				dup2(pipe3[0], STDIN_FILENO);
				dup2(pipe5[1], STDOUT_FILENO);
				int f1 = execlp("myFormat2", "myFormat2", "1", seg1, NULL);
				if(f1 == -1) printf("myFormat 1 Failed to execute\n");
				exit(0);
			}
		}
		else if (pid2 == 0){  	//Child 2: myFormat 2
			printf("CHILD PROCESS 2\n");
			close(pipe4[1]);
			close(STDIN_FILENO);
			close(pipe5[0]);
			close(STDOUT_FILENO);
			dup2(pipe4[0], STDIN_FILENO);
			dup2(pipe5[1], STDOUT_FILENO);
			int f2 = execlp("myFormat2", "myFormat2", "2", seg2,  NULL);
			if(f2 == -1) printf("myFormat 2 Failed to execute\n");
			exit(0);
		}
	}
	else if (pid1 == 0){	//Child 1 MyMerge
		printf("Child Process 1\n");
		close(pipe5[1]);
		close(STDIN_FILENO);
		dup2(pipe5[0], STDIN_FILENO);
		int merg = execlp(merger, merger, seg1, seg2, NULL);
		if(merg == -1) printf("myMerge Failed to execute\n");
		exit(0);		
	}
	exit(0);
}
