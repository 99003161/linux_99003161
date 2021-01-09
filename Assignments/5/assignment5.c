#include<sys/wait.h>
#include<stdio.h>
#include<unistd.h>
#include<operations.h>


int main()
{
int temp,status,c=0;
temp=fork();
if(temp<0)
{
printf("error");
}
else if(temp==0 && c==0)
{
execlp("gcc","gcc","sum1.c","-o","su1",NULL);
exit(0);
}
else if(temp==0 && c==1)
{
execlp("gcc","gcc","sum1.c","-o","sb1",NULL);
exit(0);
}
else if(temp==0 && c==2)
{
execlp("gcc","gcc","sum1.c","-o","mu1",NULL);
exit(0);
}
else
{
waitpid(-1,&status,0);

printf("child is created\n");
printf("status is %d",WEXITSTATUS(status));
}
}


