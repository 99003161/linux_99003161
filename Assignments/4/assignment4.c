#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{

int lines,characters, words;
int first,n,d,i;
char ch[1024];
first=open("source.txt",O_RDONLY);
if(first<0)
{
	perror("open");
	exit(1);
}
words = 0;
lines = 0;
while(n=read(first,ch,sizeof(ch)))
	{
    	for(i=0;i<n;i++)
        	{
            /* new line */
            	if (ch[i] == '\n')
               	lines++;
            /* words */
            	if (ch[i] == ' ' || ch[i] == '\t' || ch[i] == '\n')
               	words++;
        	}
        characters=n;
    }
    /* Close files to release resources */
    close(first);
int getL()
{
  printf("number of lines: %d\n",lines);
}
int getCh()
{
  printf("number of characters: %d\n",characters);
}
int getW()
{
  printf("number of words: %d\n",words);
}
getL();
getCh();
getW();
return 0;
}

