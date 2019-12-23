#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS
char *messages[NUM_THREADS];
struct thread_data{
	int thread_id;
	int sum;
	char *message;
};
struct thread_data thread_data_array[NUM_THREADS];
void *printHello(void *threadarg){
	int taskid,sum;
	char *hello_msg;
	struct thread_data *my_data;
	sleep(1);
	my_data = (struct thread_data *) threadarg;
	taskid = my_data->thread_id;
	sum = my_data->sum;
	hello_msg = my_data->message;
	printf("thread %d:%s Sum=%d",taskid,hello_msg,sum);
	pthread_exit(NULL);
}
int main(int argc,char *argv[])
{
	pthread_t threads[NUM_THREADS];
	int *taskids[NUM_THREADS];
	int rc,t,sum;
	sum=0;
	messages[0]="English: Hello world!";
	messages[1]="English1: Hello world!";
	messages[2]="English2: Hello world!";
	messages[3]="English3: Hello world!";
	messages[4]="English4: Hello world!";
	messages[5]="English5: Hello world!";
	messages[6]="English6: Hello world!";
	messages[7]="English7: Hello world!";
	for(t=0;t<NUM_THREADS;t++)
	{
		sum=sum+t;
		thread_data_array[t].thread_id=t;
		thread_data_array[t].sum=sum;
		thread_data_array[t].message=messages[t];
		printf("creating thread %d\n",t);
		rc=pthread_create(&threads[t],NULL,PrintHello,(void*)&thread_data_array[t]);
		if(rc){
			printf("ERROR,return code f is %d",rc);
			exit(-1);	
	}
	}
	pthread_exit(NULL);
}
