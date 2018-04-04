#include<string.h>
#include<sys/param.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

typedef char string[100];

int cmpfunc(const void * a, const void * b){
	const char * ia = *(const char **)a;
	const char * ib = *(const char **)b;
	return strcmp(ia, ib);
}

int main(int argc, char * argv[]){
	int i = 0;
/*	while(i < argc){
		printf("Arg: %s\n", argv[i]);
		i++;
	}	*/	
	i = 0;
	char * number;
	number = (char *)malloc(sizeof(char)*10);
	fgets(number, 11, stdin);
	int nStr = atoi(number);
	char ** data;
	char * str[nStr];
	data = str;
	while(i < nStr){
		data[i] = (char *)malloc(sizeof(char)*100);
		i++;	
	}
//	printf("K"); 
	i = 0;
	int length[nStr];
/*	if(lseek(STDIN_FILENO, 0, SEEK_SET) < 0)
		printf("Seek Fail");		*/		
	while(i < nStr){
		fgets(str[i], 101, stdin);		

	//	data[i] = data[i];
			
		length[i] = strlen(str[i])-1;
 
//		printf("%s :::", str[i]);
//		printf("%d\n", length[i]);
		i = i + 1;
	}
//	printf("%d\n", str[0]);
//	printf("test0: %s\n", str[2]);
	qsort(&str, nStr, sizeof(char*), cmpfunc);
//	printf("test: %s\n", str[2]);
//	FILE * fp;
//	fp = fopen(filename, "w+");
	

//	int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	i = 0;
	while(i < nStr){
//		printf("%s\n", str[i], length[i]);
		fputs(str[i], stdout);
//		fputs("\n",fp);	
//		write(fd, str[i], length[i]);
//		write(fd, "\n", 1);
		i++;
	}
	fputs(" ",stdout);
//	close(fd);
//	close(STDIN_FILENO); 
/*	printf("%s\n", &str[0]);
	printf("%s\n", &str[1]);
	printf("%s\n", &str[2]);
	printf("%s\n", &str[3]);	*/
//	printf("Sort Done\n");
	exit(0);
}
