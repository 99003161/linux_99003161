#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int scount,dcount,nbytes, flag;
	scount=open("source.txt",O_RDONLY);
	dcount=open("dest.txt",O_WRONLY|O_CREAT, 0666);
	if(scount<0 || dcount<0)
	{
		perror("open");
		exit(1);
	}
	int maxlen=128;
	char buf[maxlen];
	nbytes=read(scount,buf,maxlen);
	if(nbytes<0)
	{
		perror("read");
		exit(2);
	}
	flag = write(dcount,buf,nbytes);
	close(scount);
	close(dcount);
	if(flag)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	return 0;
}
