#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char * argv[]){
	if(argc < 2){
		printf("Not enough Arguments\n");
		exit(-1);
	}
	char * code = argv[1];
//	strcat(code, "#");
//	printf("%s\n", code);
	char * hold = (char *)malloc(sizeof(char)*100);
	strcpy(hold, code);
	char * buf = (char *)malloc(sizeof(char)*101);
	int size = atoi(argv[2]);
	int i = 0;
	while(i < size){
		fgets(buf, 101, stdin);
		strcpy(code, hold);
		strcat(code, buf);
		fputs(code, stdout);
		i++;
	}
	printf("Out of Format\n");
	exit(0);
}
