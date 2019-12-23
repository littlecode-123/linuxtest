#include <stdio.h>
#include <unistd.h>

int main (void)
{
	printf("pid-> %d\n",getpid());
	printf("ppid-> %d\n",getppid());
	while(1);
	return 0;
}
