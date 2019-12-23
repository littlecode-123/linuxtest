#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/param.h>
#include <signal.h>

void sigroutime(int signo)
{
	switch(signo)
	{
		case 1:
			printf("recive SIGHUP\n");
			break;
		case 2:
			printf("recive SIGINT\n");
			break;
		case 3:
			printf("recive SIGQUIT\n");
			break;
	}

}
int main()
{
	signal(1,sigroutime);
	signal(2,sigroutime);
	signal(3,sigroutime);
	printf("test process \n pid = %d\n",getpid());
	while(1);
	return 0;	
}


