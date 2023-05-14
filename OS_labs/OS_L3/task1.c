#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 1000	
int main()
{
	int fd1[2];
	int fd2[2];
	pipe(fd1);
	pipe(fd2);
	pid_t p = fork();
	if(p >= 0)
	{
		if( p == 0 )
		{
			//reading from pipe 1
			close(fd1[1]);
			char recieved1[MAXLINE];
			read(fd1[0],recieved1,sizeof(recieved1));
			printf("Recieving....\n");
			printf("~~ Message recieved from 1st pipe :%s\n\n",recieved1);
			
			//writting in pipe 2
			close(fd2[0]);
			char send2[MAXLINE];
			printf(">> Write message to 2nd pipe : ");
			fgets(send2,sizeof(send2),stdin);
			write(fd2[1],send2,sizeof(send2));
		}
		else
		{
			//writting in pipe 1
			close(fd1[0]);
			char send1[MAXLINE];
			printf("\n>> Write message to 1st pipe : ");
			fgets(send1,sizeof(send1),stdin);
			write(fd1[1],send1,sizeof(send1));
			
			wait(NULL);
			
			//reading from pipe 2
			close(fd2[1]);
			char recieved2[MAXLINE];
			read(fd2[0],recieved2,sizeof(recieved2));
			printf("Recieving....\n");
			printf("~~ Message recieved from 2nd pipe : %s\n",recieved2);
		}
	}	
}

