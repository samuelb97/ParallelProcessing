#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char * argv[]){
//	printf("argc: %d\n", argc);
/*	if(argc < 4){
		printf("Not Enough Arguments");
		exit(-1);
	}	*/
//	printf("A");
	char * pathname = argv[1];
	int stLine = atoi(argv[2]);
	int endLine = atoi(argv[3]);
	int finNo = endLine - stLine;
	char * fNo;
//	printf("B");
	fNo = (char *)malloc(sizeof(char)*10);
	sprintf(fNo, "%d", finNo);	
//	printf("fNo: %s\n",fNo);
	fputs(fNo, stdout);	
	FILE * fp = fopen(pathname, "r");
	int i = 0;
	char * buf;
	buf = (char *)malloc(sizeof(char)*101);
	while (i < stLine){
		fgets(buf, 101, fp);
		i++;
	} 
	while (i < endLine){
		fgets(buf, 101, fp);
		fputs(buf, stdout);
//		printf("buf: %s\n", buf);
		i++;
	}
	fclose(fp);
	exit(0);
}
