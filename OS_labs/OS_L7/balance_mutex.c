#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#define MAXLINE 1000
int globe = 0;
pthread_mutex_t mu;
void *deposit(void *args)
{	
	pthread_mutex_lock(&mu);
	int deposit = globe;
	deposit += 2;
	sleep(1);
	globe = deposit;
	pthread_mutex_unlock(&mu);
}
void *withdraw(void *args)
{	
	printf("\n\tWithdrawing...\n");
	pthread_mutex_lock(&mu);
	int withdraw = globe;
	if(globe>10)
		withdraw -= 10;
	else
		printf("\t!!!No Sufficient Balance!!!\n");
	sleep(1);
	globe = withdraw;
	pthread_mutex_unlock(&mu);
}
int main()
{
	pthread_t threads[4];
	
	//printf("\n\t|-------Global Variable = %d-------|\n\n",globe);
	
	for(int i=0; i<4; i+=2)
	{
		printf("\n\t-------------------------------------------\n");
		pthread_create(&threads[i],NULL,deposit,NULL);
		pthread_join(threads[i],NULL);
		printf("\n\t++ Depositing        (Balance)  = %d$\n",globe);
		
		
		pthread_create(&threads[i+1],NULL,withdraw,NULL);
		pthread_join(threads[i+1],NULL);
		printf("\t-- After Withdrawing (Balance)  = %d$\n",globe);
	}
	printf("\n\t-------------------------------------------\n\n");
	
	return 0;
}




