#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main( int argc , char*argv[]){
	FILE*fp; char ch;int sc=0;
	fp=fopen(argv[1],"r");
	if(fp==NULL)
	printf("Unable to open file: %s\n", argv[1]);
	else{
		while(!feof(fp)){
			ch=fgetc(fp);
			if(ch==' ')
			sc++;
		}
		printf("number of spaces in the program %d",sc);
		printf("/n");
		fclose(fp);
		return 0;
		}
}
