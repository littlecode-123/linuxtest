#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/param.h>
#include <signal.h>
void fun()
{
	printf("call sig callback function!\n");
	printf("mask block;\n");
	signal(2,SIG_DFL);
}
int main()
{
	int i;
	sigset_t set,pendset;
	struct sigaction sct;
	(void)signal(2,fun);
	if(sigemptyset(&set)<0)
		perror("init set dailes!\n");
	if(sigaddset(&set,2)<0)
		perror("add set failes!\n");
	if(sigprocmask(SIG_BLOCK,&set,NULL)<0)
		perror("pro set failes!\n");
	else
	{
		for(i=0;i<10;i++)
		{
			printf("%d :message send!\n",i);
			//kill(getpid(),2);
			raise(2);
			sleep(1);

		}
	}
	if(sigprocmask(SIG_UNBLOCK,&set,NULL)<0)
		perror("pro unset failes!\n");		
}

