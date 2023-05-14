#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#define MAXLINE 1000	
int main()
{
	//char *path = "/lab8/namedPipe";
	int n = mkfifo("namedPipe",0666);
	int des1;
	char recieved[MAXLINE];
	char send[MAXLINE] ;
		
	while(strcmp(send,"Goodbye")!=0)
	{
		des1 = open("namedPipe",O_WRONLY);
		printf("\n>> To Client 1   : ");
		fgets(send,sizeof(send),stdin);
		write(des1, send, strlen(send)+1);
		close(des1);
		send[strcspn(send, "\n")] = 0; 
		
		des1  = open("namedPipe",O_RDONLY);
		read(des1,recieved,sizeof(recieved));
		printf("~~ From Client 2 : %s\n",recieved);
		close(des1);
	}
	/*pid_t pid  = fork();
	if(pid >= 0)
	{
		if(pid == 0)
		{
			//reading from pipe 1
			//int read_des  = open("namedPipe",O_RDONLY);
			//sleep(2);
			//close(des);
			des  = open(path,O_RDONLY);
			char recieved[MAXLINE];
			read(des,recieved,sizeof(recieved));
			printf("Recieving....\n");
			printf("~~ Message recieved from 1st pipe :%s\n\n",recieved);
			exit(0);
		}
		else
		{
			//close(read_des);
			//int write_des = open("namedPipe",O_WRONLY);
			
			des = open(path,O_WRONLY);
			char send[MAXLINE] = "hello" ;
			//printf("\n>> Write message to 1st pipe : ");
			//fgets(send,sizeof(send),stdin);
			//int write_des = open("namedPipe",O_WRONLY);
			write(des, send, sizeof(send));
			//close(des);
			wait(NULL);
		}
	}*/

}
	
	
	
			
			

