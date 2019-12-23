#include"my.h"



#define BUFFSIZE 4096 





int main(void) 

{	

	int fd = open("./test.dat",O_RDWR);	

	if(-1 == fd)

{                 

	printf("file openerror\n");		

	return -1;         

}         

	pid_t   pid;

	pid = fork(); 

/*	int fd = open("./test.dat",O_RDWR);

if(-1 == fd)

{                 

	printf("file openerror\n");		

	return -1;         

}  */   	         

	if (pid < 0)

{                

	printf("fork error");        

}

	

	else if (pid == 0) 

{          

	/* child */					     	  	

printf("*********************child*******************\n");						

		

printf("child seek %ld\n",lseek(fd,3,SEEK_CUR));					

printf("*********************child*******************\n");        

} 

	else 

{                

	sleep(2);                               

	/* parent */			

printf("*********************parent*******************\n");		

		

printf("parent seek cur %ld\n",lseek(fd,0,SEEK_CUR));			

printf("*********************parent*******************\n");        }  		

return 0;

} 




