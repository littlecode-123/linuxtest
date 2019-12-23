#include "my.h"
#define NUM 4
struct ss
{
	int n;
	int m;
};
void fun(void *arg)
{
	int *pt;
	pt=(int *)arg;
	printf("work thread %d : tid = %p\n",(int)pt,pthread_self());
}

int main()
{
	struct ss s={5,6};
	pthread_t tid[s.n];
	int ret;
	int i;
	for(i=0;i<s.n;i++)
	{
		pthread_create(&tid[i],NULL,(void *(*))fun,(void *)i);
	}
	for(i=0;i<s.n;i++)
		pthread_join(tid[i],NULL);
	printf("ALL finishes\n");
	return 0;
}
