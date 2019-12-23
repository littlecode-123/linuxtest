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
	int fdsrc, fddes, nbytes;
	int flags=O_CREAT | O_TRUNC | O_WRONLY;
	int z;
	char buf[20], src[20], des[20],buff[5];	
	
	gettimeofday(&tv1,&tz);

	fdsrc = open("/etc/passwd", O_RDONLY);
	if(fdsrc<0){
		exit(1);
	} 
	fddes = open("b.txt", flags, 0644);
	if(fddes<0){
		exit(1);
	}
	while((nbytes=read(fdsrc, buf, 20))>0){
		z = write(fddes, buf, nbytes);
		if(z<0)
			perror("写目标文件出错");
	}
	close(fdsrc);
	close(fdsrc);
	printf("复制“/etc/passwd”文件为“b.txt”文件成功！		\n");
	gettimeofday(&tv2,&tz);	
	printf("test3:  %ld \n",tv2.tv_usec-tv1.tv_usec);
	exit(0);
}
