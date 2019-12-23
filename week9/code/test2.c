#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int x=100;
int main()
{
	int y=0;
	static int w=33;
	printf("test2:pid=%d,ppid=%d\n",getpid(),getppid());
	printf("test2:address x=%ld,y=%ld,w=%ld\n",&x,&y,&x);
	sleep(100);
	return 0;


}
