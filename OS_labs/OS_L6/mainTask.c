#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  
#include <pthread.h>
#include <time.h>
int n;
int count(int n)  
{  
    int counter=0; // variable declaration  
    while(n!=0)  
    {  
        n=n/10;  
        counter++;  
    }  
    return counter;  
} 
void *randomArrayGenerator(void *args)
{
	printf("~ Assigning random elements (thread 1)...\n");
	printf("--> Array elements are : [");
	int *array = (int*)args;
	int min = 0, max = 100;
	srand(time(0));
	for(int i=0; i<n; i++)
	{
		array[i]  = (rand() % (max - min + 1)) + min;
		printf("%d, ",array[i]);
	}
	printf("]\n");
}
void *insertionSort(void *arg){

	printf("~ Insertion sorting (thread 2)...\n");
	int *array=(int*)arg;
	//sorting
	printf("--> Array elements are : [");
	for (int i = 1; i < n; i++) 
	{
		int value = array[i];
	 	int j = i - 1;
	    	while (value < array[j] && j >= 0) 
	    	{
	    		array[j+1] = array[j];
	      		--j;
	    	}
	    	array[j+1] = value;	
	  }
	  for(int i=0; i<n; i++)
	  {
		printf("%d, ",array[i]);
	  }
	  //returning highest value
	  printf("]\n");
	  pthread_exit ( ( void *) array[n-1]) ;
} 
int main()
{
    	pthread_t tid[2];
	printf("Enter size of array : ");
	scanf("%d",&n);
	int array[n];
	
	printf("\n");
	
    	pthread_create(&tid[0], NULL, randomArrayGenerator, array);
    	pthread_join(tid[0], NULL);
    	
    	printf("\n");
    	
    	int greatest_number = 0;
    	pthread_create(&tid[1], NULL, insertionSort, array);
    	pthread_join(tid[1], &greatest_number);
    	printf("--> Greatest Number : %d\n",(int)greatest_number);
    	int size = count(greatest_number);
    	int digits[size];
    	
    	for (int i = size-1; i >= 0; i--)
	{
    		digits[i] = greatest_number % 10;
    		greatest_number = greatest_number / 10;
	}
	
	if(digits[0]==digits[size-1])
		printf(":) Palindrome\n");
	else
		printf(":( Not Palindrome\n");
	
}
