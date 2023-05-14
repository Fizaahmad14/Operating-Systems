#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
void *T_odd(void*args)
{
	int odd = 1;
	printf(" ______________________________\n");
	printf("|                              |\n");
	printf("|-------ODD NUMBERS < 20-------|\n");
	printf("|______________________________|\n");
	while(odd<20)
	{
		printf("\t-Odd : %d\n",odd);
		odd += 2;
	}
	
}
void *T_even(void*args)
{
	int even = 0;
	printf(" _______________________________\n");
	printf("|                               |\n");
	printf("|-------EVEN NUMBERS < 20-------|\n");
	printf("|_______________________________|\n");
	while(even<20)
	{
		printf("\t-Even : %d\n",even);
		even += 2;
	}
	
}
int main()
{
	pthread_t t1,t2;
	pthread_create(&t1, NULL, T_even, NULL);
	pthread_join(t1, NULL);
	
	pthread_create(&t2, NULL, T_odd, NULL);
	pthread_join(t2, NULL);
	return 0;
}
