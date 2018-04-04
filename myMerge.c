#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char * argv[]){
	if(argc < 2){
		printf("Not Enough Arguments\n");
		exit(-1);
	}
	char * n1 = argv[1];
	char * n2 = argv[2];
	int nStr1 = atoi(n1);
	int nStr2 = atoi(n2);
	int total = nStr1 + nStr2;

	char * data1[nStr1+1];
	char * data2[nStr2+1];
	char * data[total];
	int i = 0;
	while(i < nStr2+1){
		data2[i] = (char *)malloc(sizeof(char)*101);
		i++;
	}
	i = 0;
	while(i < nStr1+1){
		data1[i] = (char *)malloc(sizeof(char)*101);
		i++;
	}
	i = 0;
	while(i < total){
		data[i] = (char *)malloc(sizeof(char)*101);
		i++;
	}
	data1[nStr1] = "+++";
	data2[nStr2] = "+++";
	i = 0;
	int j = 0;
	int k = 0;
	int check = 0;
	char * buf = (char *)malloc(sizeof(char)*1000);
	printf("In myMerge\n");
	while(i < total){
//		printf("In Merge Loop\n");
		check = fgetc(stdin);
		fgets(data[i], 101, stdin);
//		printf("Got fgets\n");
		if(check == 50){
		//	printf("Data 2: %s\n", buf);
			data2[j] = data[i];
			j++;
		}
	//	printf("Not Check 50\n");
		else{
		//	printf("Data 1: %s\n", buf);
			data1[k] = data[i];
			k++;	
		}
		i++;
	}
	printf("Got Merge Data\n");
	i = 0;
	j = 0;
	k = 0;
	while(i < total+1){
		if(data1[k] == "+++" && data2[j] == "+++"){
		//	printf("Both NULL\n");
			break;
		}
		else if(data1[k] == "+++"){
		//	printf("1 NULL: ");
			fputs(data2[j], stdout);
			j++;
		}
		else if(data2[j] == "+++"){
		//	printf("2 NULL: ");
			fputs(data1[k], stdout);
			k++;
		}
		else if(strcmp(data1[k],data2[j]) < 0){
		//	printf("1 < 2: ");
			fputs(data1[k], stdout);
			k++;
		}
		else{
		//	printf("ZZ");
		//	printf("2 < 1: ");
			fputs(data2[j], stdout);
			j++;
		}
		i++;
	}			
	exit(0);
}
