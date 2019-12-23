#include "my.h"
extern int get_user_cmd();
enum command {QUIT=0,WROK};

struct thread{
	int no;
	enum command cmd;
};
void thread_func(struct thread *);
enum command get_usr_cmd()
{
	int cmd;
	printf("Please enter a command number(0.9)");
	scanf("%d",&cmd);
	return (enum command)cmd;
}

main(void)
{
	pthread_t tid;
	int rv,cmd,k=0;
	struct thread *last_thread,*tp;
	while(1){
	cmd=get_usr_cmd();
	if(cmd == QUIT){
	printf(" fish soon");
	pthread_exit((void *)NULL);
}
tp=(struct thread *)malloc(sizeof(struct thread));
tp->no=k++;
tp->cmd = cmd;
rv=pthread_create(&tid,NULL,(void*(*)())thread_func,(void *)tp);
check_error(rv,"pthread_detach()");
printf("create thrread %d\n",tp->no);

rv=pthread_detach(tid);
check_error(rv,"othread_detach()");
}
}
void thread_func(struct thread *thread_p)
{
	printf("\n thread %d creat with  num %d is run\n",thread_p->no,thread_p->cmd);
	sleep(thread_p->cmd);
	printf("\nthread %d finish now\n",thread_p->no);
	pthread_exit(NULL);
}
