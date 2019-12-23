#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>

int main(){

	struct timeval tv1,tv2;
	struct timezone tz;
	
	FILE* fdsrc;
	FILE* fddes;
	
	char buf[20], src[20], des[20],buff[5];

	gettimeofday(&tv1,&tz);	
	
	fdsrc = fopen("/etc/passwd", "rt");
	if(fdsrc==NULL){
		exit(1);
	} 
	fddes = fopen("a.txt", "wt");
	if(fddes==NULL){
		exit(1);
	}
	while(!feof(fdsrc)){
		if(fputc(fgetc(fdsrc),fddes)==EOF)
	{
		perror("写目标文件出错");
	}		
	}
	fclose(fdsrc);
	fclose(fddes);
	printf("复制“/etc/passwd”文件为“a.txt”文件成功！		\n");
	gettimeofday(&tv2,&tz);	
	printf("test3_1:  %ld \n",tv2.tv_usec-tv1.tv_usec);
	exit(0);
}
