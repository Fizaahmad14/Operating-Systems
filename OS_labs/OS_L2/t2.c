#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
//#include <conio.h>
int main()
{
	//Main task
	int x1,x2,temp,hcf,lcm;
	printf("***-TO CALCULATE HCF-***\n~~ Enter Numbers\n");
	printf(">>  1st - ");
	int num1;
	scanf("%d",&num1);
	printf(">>  2nd - ");
	int num2;
	scanf("%d",&num2);
	x1 = num1;
	x2 = num2;
	while(x2!=0)
	{
		temp = x2;
		x2 = x1 % x2;
		x1 = temp;
	}
	hcf = x1;
	printf("--> HCF = %d\n",hcf);  
	
	pid_t pid = fork();
	if(pid >= 0)
	{
		//printf("eror");
		if(pid == 0)
		{
	                                                                       
		}			
		else
		{	
			int half = hcf/2;
			int flag = 0;
			for(int i=2; i<=half; i++)
			{
				if(hcf%i == 0)
				{
					flag = 1;
					break;
				}
			}
			if(flag==0)
			{
				printf("--> %d is prime\n",hcf);
				hcf++;
				pid_t pid2 = fork();
				//grand parent
				if(pid2>0)
				{
					//grand parent
					printf("--> %d after increment prime\n",hcf);
					char convert_to_char[20];
					sprintf(convert_to_char,"%d",hcf);
					char *list[] = {"t3.out",convert_to_char, NULL};
					execv("./t3",list);
				}
			}                                       
		}
		
	}
}

