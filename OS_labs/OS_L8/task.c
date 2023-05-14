
//Example 1
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
# include <semaphore.h>
sem_t sem;
int acc1 = 50;
int acc2 = 50;
void *deposit(void *args)
{	
	printf("\n\tDepositing...\n");
	sem_wait(&sem);
	int deposit = acc1;
	deposit += 11;
	sleep(1);
	acc1 = deposit;
	sem_post(&sem);
	 pthread_exit(NULL);
}
void *withdraw(void *args)
{	
	
	printf("\n\tWithdrawing...\n");
	sem_wait(&sem);
	//int withdraw = globe;
	if(acc1>10)
		acc1 -= 10;
	else
		printf("\t!!!No Sufficient Balance!!!\n");
	sleep(1);
	//globe = withdraw;
	sem_post(&sem);
	 pthread_exit(NULL);
}
void *withdraw2(void *args)
{	
	
	printf("\n\tWithdrawing...\n");
	sem_wait(&sem);
	//int withdraw = globe;
	if(acc2>10)
	{
		acc2 -= 10;
		acc1 -= 10;
	}
	else
		printf("\t!!!No Sufficient Balance!!!\n");
	sleep(1);
	//globe = withdraw;
	sem_post(&sem);
	 pthread_exit(NULL);
}
int main(){
     pthread_t t[5];
     sem_init(&sem,0,2);
       printf("\n\t++ Depositing        (Balance)  = %d$\n",acc1);
     // for first account
     pthread_create(&t[0],NULL , withdraw,NULL);
     
     pthread_create(&t[1],NULL , withdraw,NULL);
    
     pthread_create(&t[2],NULL , deposit,NULL);
     
     //for second account
     pthread_create(&t[3],NULL , withdraw2,NULL);
    
     pthread_create(&t[4],NULL , withdraw2,NULL);
   
     
     pthread_join(t[0],NULL);
     printf("\t-- After Withdrawing from account 1(Balance)  = %d$\n",acc1);
     pthread_join(t[1],NULL);
      printf("\t-- After Withdrawing from account 1(Balance)  = %d$\n",acc1);
     pthread_join(t[2],NULL);
     printf("\n\t++ Depositing        (Balance)  = %d$\n",acc1);
     pthread_join(t[3],NULL);
      printf("\t-- After Withdrawing from account 2(Balance)  = %d$\n",acc2);
     pthread_join(t[4],NULL);
      printf("\t-- After Withdrawing from account 2(Balance)  = %d$\n",acc2);
     pthread_exit(NULL);
}
