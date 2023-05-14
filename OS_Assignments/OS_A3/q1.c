#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#define MAXLINE 1000
char filename[20];
void *countLetters(void *args)
{	
	FILE *file_pointer;
	file_pointer = fopen(filename,"r");
	char *character = (char*)args;
	char charactersInFile[MAXLINE];
	int i = 0;
	char ch;
	int count = 0;
	int size = 0;
	while ((ch = fgetc(file_pointer)) != EOF)
	{
		if(ch == character[0])
			count++;
		
	}
	fclose(file_pointer);
	pthread_exit ( ( void *) count) ;
}
int main()
{
	
	printf("\n\t>> Enter filename : ");
	scanf("%s",filename);
	FILE *file_pointer;
	file_pointer = fopen(filename,"r");
	char ch;
	printf("\t--> Data in %s  : ",filename);
	while ((ch = fgetc(file_pointer)) != EOF)
	{
		printf("%c",ch);
		
	}
	printf("\n");
	int count = 0;
	char char_array[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	pthread_t threads[26];
	for(int turn = 0; turn < 26; turn++)
	{
		pthread_create(&threads[turn], NULL, countLetters, &char_array[turn]);
	}
	printf("\t<><><><><><><><><><><><><Frequencies \n");
	for(int turn = 0; turn < 26; turn++)
	{
		pthread_join(threads[turn], &count);
		printf("\n\t* %c = %d",char_array[turn],(int)count);
	}
	printf("\n\n");
	return 0;
}





