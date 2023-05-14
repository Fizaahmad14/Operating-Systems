#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
# include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <pthread.h>

void *summation( void *arg ) 
{
	int result = 0;
	int *array = (int*)arg;
	result = array[0]+array[1];
	printf("Summation done using thread 1 \n" ) ;
	pthread_exit ( ( void *) result) ;
}

void *subtraction(void *arg)
{
	int result = 0;
	int *array = (int*)arg;
	result = array[0]-array[1];
	printf("Subtraction done using thread 2 \n" ) ;
	pthread_exit ( ( void *) result) ;
}

void *multiplication( void *arg ) 
{
	int result=1;
	int *array=(int*)arg;
	result=array[0]*array[1];
	printf("Multiplication done using thread 3 \n" ) ;
	pthread_exit ( ( void *) result) ;
}

void *division(void *arg)
{
	int result=1;
	int *array=(int*)arg;
	result=array[0]/array[1];
	printf("Division done using thread 4 \n" ) ;
	pthread_exit ( ( void *) result) ;
}
void menu()
{
	printf(" ________________________________\n");
	printf("|                                |\n");
	printf("|-----------CALCULATOR-----------|\n");
	printf("|________________________________|\n");
	printf("|                                |\n");
	printf("|1.          Addition            |\n");
	printf("|2.        Subtraction           |\n");
	printf("|3.       Multiplication         |\n");
	printf("|4.          Division            |\n");
	printf("|________________________________|\n");
}
int main ( void ) 
{
	int var1;
	int var2;
	int choice;
	menu();
	printf("\n--> Enter the operation you want to perform: ");
	scanf("%d",&choice);
	printf(">> First Number : ");
	scanf("%d",&var1);
	printf(">> Second number: ");
	scanf("%d",&var2);
	int arr[2]={var1,var2};
	/*for (int i=0;i<2;i++)
	{	
		printf("Array elements: %d\n",arr[i]);
	} */
	pthread_t tid1 , tid2,tid3,tid4 ;
	if(choice==1){
		void *tret1;
		pthread_create (& tid1 , NULL, summation , arr) ;
		pthread_join (tid1 , &tret1) ;
		printf("Thread 2 output of addition is: %ld\n" , ( long ) tret1) ;
	}
	else if(choice == 2){
		void *tret2;
		pthread_create (& tid2 , NULL, subtraction , arr) ;
		pthread_join (tid2 , &tret2) ;
		printf("Thread 2 output of subtraction is: %ld\n" , ( long ) tret2) ;
	}
	else if(choice == 3){
		void *tret3;
		pthread_create (& tid3 , NULL,multiplication  , arr) ;
		pthread_join (tid3 , &tret3) ;
		printf("Thread 1 output of multiplication is: %ld\n" , ( long ) tret3) ;
	}
	else if(choice == 4){
		void *tret4;
		pthread_create (& tid4 , NULL, division , arr) ;
		pthread_join (tid4 , &tret4) ;
		printf("Thread 2 output of division is: %ld\n" , ( long ) tret4) ;
	}	
	
	exit( 0 ) ;
}
