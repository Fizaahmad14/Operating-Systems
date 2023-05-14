#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 1000	
int main()
{
	int fd1[2];
	pipe(fd1);
	
	//writting in pipe 1
	char send1[MAXLINE];
	printf("\n>> Write message to 1st pipe : ");
	fgets(send1,sizeof(send1),stdin);
	write(fd1[1],send1,sizeof(send1));
		
	//reading from pipe 1
	char recieved1[MAXLINE];
	read(fd1[0],recieved1,sizeof(recieved1));
	printf("Recieving....\n");
	printf("~~ Message recieved from 1st pipe :%s\n\n",recieved1);
}
	
	
	
			
			

