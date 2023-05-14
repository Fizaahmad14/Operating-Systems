#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#define MAXLINE 1000
void *T_createFile(void *args)
{
	int odd = 1;
	printf(" ______________________________________\n");
	printf("|                                      |\n");
	printf("|-------Creating File (Thread 1)-------|\n");
	printf("|______________________________________|\n");
	open("fileForTask2.txt",O_CREAT,0777);
	printf("\n--* File created Successfully *--\n");
	
}
void *T_writeInFile(void*args)
{
	int even = 0;
	printf(" ________________________________________\n");
	printf("|                                        |\n");
	printf("|-------Writing in file (Thread 2)-------|\n");
	printf("|________________________________________|\n");
	FILE *file_pointer;
	printf("\n>> Write Message into File  : ");
	char write[MAXLINE];
	fgets(write,sizeof(write),stdin);
	file_pointer = fopen("fileForTask2.txt","w");
	fputs(write, file_pointer);
	fclose(file_pointer);
	printf("\n--* Written Successfully *--\n\n");
	
}
int main()
{
	pthread_t t1,t2;
	pthread_create(&t1, NULL, T_createFile, NULL);
	pthread_join(t1, NULL);
	
	pthread_create(&t2, NULL, T_writeInFile, NULL);
	pthread_join(t2, NULL);
	return 0;
}
