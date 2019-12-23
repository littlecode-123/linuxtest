#include "my.h"
#define NUM_THREADS 4
struct info{
	int no;
	int n;
};
struct rval{
	int sum;
	pthread_t tid;
};
void hello(void * t)
{
	pthread_t my_tid;
	struct info *y;
	int s=0;
	y=(struct info *)(t);
	for(int i =0;i<=y->n;i++)
		s+=i;
	my_tid=pthread_self();
	printf("\t Thread &d:my tid is %lx,Hello world\n",(int)y->no,my_tid);
	printf("\t Thread &d:sum 1 to %d is %d\n",(int)y->no,y->n,s);

}
int main()
{
	pthread_t tid;
	struct info s[4];
	int rv,t;
	for(t=0;t<NUM_THREADS;t++)
	{
		a[t].no=t;
		a[t].n=100*(t+1);
		rv=pthread_create(&tid,NULL,(void *(*)())hello,(void*)&a[t]);
		if(rv!=0)
	}
}

