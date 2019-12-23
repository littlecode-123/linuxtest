#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int g=99;
int main()
{
	int i,pid;
	static int f=19;
	pid=fork();
	if(pid<0)
	{
		perror("fork failed!\n");
		exit(1);
	}
	else if(pid==0)
	{
		printf("chid:pid=%d,ppid=%d\n",getpid(),getppid());
		i=100;
		g=101;
		f=238;
		printf("chid:i=%d,g=%d,f=%d\n",i,g,f);
		exit(123);
	}
	printf("parent:pid=%d,ppid=%d\n",getpid(),getppid());
	printf("parent:i=%d,g=%d,f=%d\n",i,g,f);
	return 0;
}