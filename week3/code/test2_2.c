#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include"ourhdr.h"

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(void){
	int fd;
	if((fd = creat("file.hole",0644)) < 0)
		perror("creat error");
	if(write(fd,buf1,10) != 10)
		perror("buf1 write error");
	if(lseek(fd,40,SEEK_SET) == -1)
		perror("lseek error");
	if(write(fd,buf2,10) != 10)
		perror("buf2 write error");
	exit(0);
}
