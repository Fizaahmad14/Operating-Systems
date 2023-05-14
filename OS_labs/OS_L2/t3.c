#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	//Main task
	int temp = atoi(argv[1]);
	printf("--> Multiples of %d < 100\n",temp);
	//printf("1");
	int i = 1;
	int hcf = temp;
	while(hcf < 100)
	{
		hcf = temp* i;
		if(hcf<100)
			printf("%d x %d = %d\n",temp,i,hcf);
		i++;	
	}
}

