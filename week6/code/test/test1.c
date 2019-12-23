#include "lib.h"
#include <dlfcn.h>
int main()
{
	int a[UNUMBER];
	void *handle;
	int (*f1)(),(*f2)();
	void (*f3)();
	char* error;

	handle = dlopen("/home/mouslet/linuxprograme/week6/code/dynamiclib/dynamicclib.so",RTLD_LAZY);
	if(!handle)
	{
		fprintf(stderr,"%s/n",dlerror());
		exit(1);
	}
	f1=dlsym(handle,"max");
	if((error=dlerror())!=NULL)
	{
		fprintf(stderr,"%s/n",dlerror());
		exit(1);
	}
	f2=dlsym(handle,"sum");
	if((error=dlerror())!=NULL)
	{
		fprintf(stderr,"%s/n",dlerror());
		exit(1);
	}
	f3=dlsym(handle,"urand");
	if((error=dlerror())!=NULL)
	{
		fprintf(stderr,"%s/n",dlerror());
		exit(1);
	}
	f3(a,UNUMBER);
	printf("max = %d",f1(a,UNUMBER));
	printf("sum = %d",f2(a,UNUMBER));
	if(dlclose(handle)<0)
	{
		fprintf(stderr,"%s/n",dlerror());
		exit(1);
	}
	return 0;
}
