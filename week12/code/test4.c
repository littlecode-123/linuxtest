#include "my.h"
int count=0;
int main()
{
//
	char* msg;
	char* msg1;
    char buf[20];
    int pipe_filed[2],pipe_filed1[2];
    pipe(pipe_filed);
	pipe(pipe_filed1);
//
	pid_t p1,p2,p3;
	p1=fork();
	int s1,s2,s3,r1,r2,r3;
	if(p1<0)
	{
		perror("fork1 failed\n");
		return -1;
	}
	else if(p1==0)
	{
		count+=1;
//
		msg = "p1-p2";
        write(pipe_filed[1], msg, sizeof(msg));
        printf("p1 process send: %s\n", msg);
//
		printf("child pid=%d,ppid=%d,count=%d\n",getpid(),getppid(),count);
		exit(99);
	}
	else
	{
		printf("parent fork second time\n");
		p2=fork();
		if(p2<0)
		{
			perror("fork failed.\n");
			return -1;
		}
		else if(p2==0)
		{
			count+=1;
//
			read(pipe_filed[0], buf, sizeof(buf));
  	        printf("p2 process recv: %s\n", buf);
			
//
			msg1 = "p2-p3";
        	write(pipe_filed1[1], msg1, sizeof(msg1));
        	printf("p2 process send: %s\n", msg1);
    	    
//
			printf("child pid=%d,ppid=%d,count=%d\n",getpid(),getppid(),count);
			exit(34);
		}
		else
		{
			printf("parent fork third time\n");
			p3=fork();
			if(p3<0)
			{
				perror("fork failed.\n");
				return -1;
			}
			else if(p3==0)
			{
				count+=1;
//
				read(pipe_filed1[0], buf, sizeof(buf));
  	        	printf("p3 process recv: %s\n", buf);
//
				printf("child pid=%d,ppid=%d,count=%d\n",getpid(),getppid(),count);
				exit(77);
			}
			else{
				printf("parent waiting\n");
				r1=wait(&s1);
				r2=wait(&s2);
				r3=wait(&s3);
				printf("r1=%d,s1=%d,r2=%d,s2=%d,r3=%d,s3=%d",r1,WEXITSTATUS(s1),r2,WEXITSTATUS(s2),r3,WEXITSTATUS(s3));
				printf("parent pid = %d,count=%d\n",getpid(),count);
				return 0;
			}
		}
	}

}
