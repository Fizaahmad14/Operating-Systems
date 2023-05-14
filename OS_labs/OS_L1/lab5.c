#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int main()
{

	//Main task
	int status;
	int num1 = 0, num2 = 0, num3 = 0, larger = 0;
	printf("***-TO CALCULATE GREATER NUMBER-***\n~~ Enter Numbers\n");
	printf(">> 1st - ");
	scanf("%d",&num1);
	printf(">> 2nd - ");
	scanf("%d",&num2);
	printf(">> 3rd - ");
	scanf("%d",&num3);
			
	if(num1>num2 && num1>num3)
	{
		larger = num1;
		printf("--> Larger of %d, %d, %d is = %d\n",num1,num2,num3,larger);
	}	
	else if(num2>num1 && num2>num3)
	{
		larger = num2;
		printf("--> Larger of %d, %d, %d is = %d\n",num1,num2,num3,larger);
	}
	else
	{
		larger = num3;
		printf("--> Larger of %d, %d, %d is = %d\n",num1,num2,num3,larger);
	}
	pid_t pid1 = fork();
	if(pid1 >= 0)
	{
		if(pid1 == 0)
		{
			printf("\n-------Calculating Square from Child\n");
			int square = larger*larger;
			printf("--> Square of %d is = %d\n",larger,square);
			exit(square);	                                                                       
		}			
		else
		{	
			wait(&status);
			int recieve_from_child = WEXITSTATUS(status);
			if(recieve_from_child % 2 == 0)
			{
				printf("\n-------Checking %d is even? from Parent\n",recieve_from_child);
				printf("--> %d is even\n", recieve_from_child);
				int even = recieve_from_child; 
				pid_t pid2 = fork();
				if(pid2 >= 0)
				{
					if(pid2 == 0)
					{
						exit(even);
					}
					else
					{
						wait(&status);
						int n = WEXITSTATUS(status);
						int multiple = 1;
						int i = 1;
						printf("\n-------Displaying Multiples < 50 from Parent of another Process\n");
						while(multiple <= 50)
						{
							printf("--> %d x %d = %d\n",n,i,n*i);
							i++;
							multiple = n*i;	
						}
					}
				}

			}
			                                                 
		}		
	}
}
