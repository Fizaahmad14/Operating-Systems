#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#define MAXLINE 1000
/*Link-----------------------------------https://www.programiz.com/dsa/merge-sort*/
// Merge two subarrays L and M into arr
int new_size = 0;
void merge(int arr[], int p, int q, int r) 
{
	int n1 = q - p + 1;
	int n2 = r - q;
	int L[n1], M[n2];
	for(int i = 0; i < n1; i++)
		L[i] = arr[p + i];
	for(int j = 0; j < n2; j++)
	    	M[j] = arr[q + 1 + j];
	    	
	int i, j, k;
	i = 0;
	j = 0;
	k = p;
	while(i < n1 && j < n2) 
	{
		if (L[i] <= M[j]) 
		{
	      		arr[k] = L[i];
	      		i++;
	    	} 
	    	else 
	    	{
	      		arr[k] = M[j];
	      		j++;
	    	}
	    	k++;
	}
	while(i < n1) 
	{
		arr[k] = L[i];
		i++;
	    	k++;
	}
	while(j < n2) 
	{
		arr[k] = M[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r) 
{
	if(l < r) 
	{
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
  	}
}
void *sortInThread(void *args)
{	
	int *array = (int *)args;
	mergeSort(array,0,new_size-1);
}
int main()
{
	int core = 2;
	int size = 0;
	printf("\t _______________________________________\n");
	printf("\t|                                       |\n");
	printf("\t|______________INFORMATION______________|\n");
	printf("\t|                                       |\n");
	printf("\t|  Number of Cores = %d                  |\n",core);
	printf("\t|  MAC Address     = 00-50-56-C0-00-01  |\n");
	printf("\t|_______________________________________|\n");
	
	printf("\n\t* Note : %d cores mean, %d threads to be make",core,core);
	printf("\n\t         Now, Enter size and elements of an array(A[size])\n");
	printf("\n\t>> Size = ");
	scanf("%d",&size);
	int array[size];
	int entry = 0;
	printf("\n\t* Elements");
	printf("\n\t{------------------A( Parent array )--}\n");
	for(int i = 0; i < size; i++)
	{
		printf("\t>> A[%d] = ",i);
		scanf("%d",&entry);
		array[i] = entry;	
	}
	//dividing
	new_size = size/2;
	int sub_array1[new_size];
	int sub_array2[new_size];
	int sort_array1[new_size];
	int sort_array2[new_size];
	for(int i = 0; i < new_size; i++)
	{
		sub_array1[i] = array[i];
		sub_array2[i] = array[i+new_size];	
	}
	//-----------------------------------------------PARENT ARRAY 
	printf("\n\t~A(initial Array)");
	printf("\n\tA[] = { ");
	for(int i = 0; i < size; i++)
	{
		printf("%d ",array[i]);	
	}
	printf("}\n");
	pthread_t threads[core];
	
	//-----------------------------------------------SUB ARRAY 1
	printf("\n\t*-------------------------------------*\n");
	printf("\n\t~A1(sub-array 1)...");
	printf("\n\tA1[] = { ");
	for(int i = 0; i < new_size; i++)
	{
		printf("%d ",sub_array1[i]);	
	}
	printf("}\n");
	pthread_create(&threads[0], NULL, sortInThread, &sub_array1);
	printf("\n\t~sorting(thread 1)...");
	pthread_join(threads[0], NULL);
	printf("\n\tA1[] = { ");
	for(int i = 0; i < new_size; i++)
	{
		printf("%d ",sub_array1[i]);	
	}
	printf("}\n");
	
	//-----------------------------------------------SUB ARRAY 2
	printf("\n\t*-------------------------------------*\n");
	printf("\n\t~A2(sub-array 2)...");
	printf("\n\tA2[] = { ");
	for(int i = 0; i < new_size; i++)
	{
		printf("%d ",sub_array2[i]);	
	}
	printf("}\n");
	pthread_create(&threads[1], NULL, sortInThread, &sub_array2);
	printf("\n\t~sorting...");
	pthread_join(threads[1], NULL);
	printf("\n\tA2[] = { ");
	for(int i = 0; i < new_size; i++)
	{
		printf("%d ",sub_array2[i]);	
	}
	printf("}\n");
	
	//-----------------------------------------------JOINED ARRAYS
	printf("\n\t*-------------------------------------*\n");
	for(int i = 0; i < new_size; i++)
	{
		array[i] = sub_array1[i];
		array[i + new_size] = sub_array2[i];	
	}
	printf("\n\t~A(joining A1 and A2)...");
	printf("\n\tA[] = { ");
	for(int i = 0; i < size; i++)
	{
		printf("%d ",array[i]);	
	}
	printf("}\n");
	printf("\n\t~final sorting...");
	mergeSort(array,0,size-1);
	printf("\n\tA[] = { ");
	for(int i = 0; i < size; i++)
	{
		printf("%d ",array[i]);	
	}
	printf("}\n");
	printf("\n");
	return 0;
}




