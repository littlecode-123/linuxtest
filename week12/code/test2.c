#include "my.h"
int main()
{
pid_t p;
char w_buf[100],r_buf[100];
int fd[2],wn,rn;
memset(w_buf,0,100);
memset(r_buf,0,100);
pipe(fd);
p=fork();
if(p<0)
{
perror(" fork fatled.\n" );
return -1;
}
else if(p==0)
{
close(fd[0]);
printf( "chlld pld=%d\n ",getpid());
sprintf(w_buf," child is running pid=%d ",getpid());
if((wn=write(fd[1],w_buf,sizeof(w_buf)))<0)
{
printf("rite faied \n");
exit(-1);
}
printf(" child writa popipe %d byte\n ",wn);
close(fd[1]);
exit(0);
}
else
{
close(fd[1]);
wait(NULL);
if((rn=read(fd[0],r_buf,sizeof(r_buf)))<0)
{
printf( "read faled\n" );
exit(-1);
}
printf( "parent fead fromotal =%d， cContent %s ",rn,r_buf);
return 0;
}
}
