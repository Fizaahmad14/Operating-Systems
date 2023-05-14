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
	int des2;
	char recieved[MAXLINE];
	char send[MAXLINE] ;
	while(strcmp(send,"Goodbye")!=0)
	{
		
		des2  = open("namedPipe",O_RDONLY);
		read(des2,recieved,sizeof(recieved));
		printf("~~ From Client 1 : %s\n",recieved);
		close(des2);
		
		des2 = open("namedPipe",O_WRONLY);
		printf("\n>> To 1st pipe   : ");
		fgets(send,sizeof(send),stdin); 
		//int write_des = open("namedPipe",O_WRONLY);
		write(des2, send, strlen(send)+1);
		close(des2);
		send[strcspn(send, "\n")] = 0;
	}
}
