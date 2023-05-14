#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#define MAXLINE 1000
int globe = 5;
pthread_mutex_t mu;
void *increment(void *args)
{	
	pthread_mutex_lock(&mu);
	int i = globe;
	i++;
	sleep(1);
	globe = i;
	pthread_mutex_unlock(&mu);
}
void *decrement(void *args)
{	
	pthread_mutex_lock(&mu);
	int i = globe;
	i--;
	sleep(1);
	globe = i;
	pthread_mutex_unlock(&mu);
}
int main()
{
	pthread_t threads[2];
	
	printf("\n\t|-------Global Variable = %d-------|\n\n",globe);
	
	pthread_create(&threads[0],NULL,increment,NULL);
	printf("\t++ Calling increment function\n");
	pthread_join(threads[0],NULL);
	
	
	pthread_create(&threads[1],NULL,decrement,NULL);
	printf("\t-- Calling decrement function \n");
	pthread_join(threads[1],NULL);
	
	
	printf("\n\t|-------Global Variable = %d-------|\n\n",globe);
	
	return 0;
}




