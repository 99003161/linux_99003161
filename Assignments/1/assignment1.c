
#include "command.h"
int main()
{
	pid_t ret; 
       int status;
	printf("welcome...pid=%d\n",getpid());
	ret=fork(); // if return value of fork() is 0 then it is a child process and if it is greater than zero then it is in parent process
	
	if(ret<0)
	{
		perror("fork");
		exit(1);
	}
	if(ret==0)
	{
		printf("child--hello,pid=%d,ppid=%d\n",
				getpid(),getppid());

		int k;
                char b[]="/usr/bin/";
               char s[50];
               printf("enter the command you want to execute");
                scanf("%s",s);
                strcat(b, s);          
                execlp(b,s,NULL);

	}
	else
	{
waitpid(-1, &status, 0);                             
 
		printf("parent--hello,pid=%d,ppid=%d\n",
				getpid(),getppid());
	}
	return 0;
}
