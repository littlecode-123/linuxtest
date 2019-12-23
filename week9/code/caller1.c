#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
	int ret;
	printf("caller1:pid=%d,ppid=%d\n",getpid(),getppid());
	ret=system("/home/mouslet/linuxprograme/week9/code/test2");
	printf("after calling\n");
	return 0;
}
