#include "cmp.h"
int main()
{
int temp,status;
temp=fork();
if(temp<0)
{
printf("error");
}
else if(temp==0)
{
execlp("gcc","gcc","assignment1.c","-o","as1",NULL);
exit(0);
}
else
{
waitpid(-1,&status,0);
printf("child is created\n");
printf("status is %d",WEXITSTATUS(status));
}
}


