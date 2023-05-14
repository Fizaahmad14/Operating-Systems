#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#define MAXLINE 1000
void *resultant(void *args)
{	
	int *to_solve = (int *)args;
	/*for(int i = 0; i < 6; i++)
	{
		printf("\n%d",to_solve[i]);
	} */
	int result = 0 ;
	for(int i = 0; i < 3; i++)
	{
		result += to_solve[i]*to_solve[i+3];
	} 
	pthread_exit ( ( void *) result) ;
}
int main()
{
	printf("\t __________________________\n");
	printf("\t|                          |\n");
	printf("\t|-------Enter M1, M2-------|\n");
	printf("\t|__________________________|\n");
	int matrix_order = 3;
	int m1[matrix_order][matrix_order];
	int m2[matrix_order][matrix_order];
	int entry = 0;
	printf("\n\t{-----------------------M1( MATRIX 1 )--}\n");
	for(int i = 0; i < matrix_order; i++)
	{
		for(int j = 0; j < matrix_order; j++)
		{
			
			printf("\tM1[%d][%d] = ",i,j);
			scanf("%d",&entry);
			m1[i][j] = entry;
		}
		
	}
	printf("\n\t{-----------------------M2( MATRIX 2 )--}\n");
	for(int i = 0; i < matrix_order; i++)
	{
		for(int j = 0; j < matrix_order; j++)
		{
			
			printf("\tM2[%d][%d] = ",i,j);
			scanf("%d",&entry);
			m2[i][j] = entry;
		}
		
	}
	printf("\t __________________________\n");
	printf("\t|                          |\n");
	printf("\t|-------M1 x M2 = M3-------|\n");
	printf("\t|__________________________|\n");
	printf("\n\t{-----------------------M3( MATRIX 3 )--}\n");
	pthread_t threads[9];
	int to_solve[6];
	int row_m1 = 0, col_m1 = 0;
	int row_m2 = 0, col_m2 = 0;
	int result = 0;
	for(int turn = 0; turn < 9; turn++)
	{
		for(int i = 0; i < matrix_order; i++)
		{
			//printf("Entry_M1[%d] = %d\n",i,m2[row_m1][col_m1]);
			//printf("Entry_M2[%d] = %d\n",i,m2[row_m2][col_m2]);
			to_solve[i]   = m1[row_m1][col_m1];
			to_solve[i+3] = m2[row_m2][col_m2];
			col_m1++; row_m2++;
		}
		pthread_create(&threads[turn], NULL, resultant, &to_solve);
		pthread_join(threads[turn], &result);
		printf("\tM3[%d][%d] = %d\n",row_m1,col_m2,result);
		row_m2 = 0; col_m2++; col_m1 = 0;
		if(col_m2 > 2)
		{
			col_m2 = 0;
			row_m1++;	
		}
		
	}
	printf("\n");
	/*for(int turn = 0; turn < 2; turn++)
	{
		printf("\n");
		pthread_join(threads[turn], &result);
		printf("result = %d",(int)result);
	}*/
	return 0;
}




