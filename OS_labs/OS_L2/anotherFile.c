#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{

	printf("\n~I am replaced process\n");
	printf("~My pid is %d\n",getpid());
	printf("--> Output from me is : ");
	for(int i=0; i<argc; i++)
	{
		printf("%s ",argv[i]);
	}
	printf("\n");


}

