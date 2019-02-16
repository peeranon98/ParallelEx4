#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define N 100
#define T 4
int main() {
	int i;     
	int A[100];      
	srand(1234);     /* Set random seed */      
	for (i=0; i < 100; i++){
		A[i] = rand()%1000;   /* Set each element randomly to 0-999 */ 
	}
	#pragma omp parallel private(i) num_threads(T)
	{
		int chunkSize = N/T;
		int tid = omp_get_thread_num();
		int start = tid*chunkSize;
		int end = (tid+1)*chunkSize-1;
		for (i=start; i <= end; i++){
			A[i] *= 10;
		}		
	}
	printf("Parallel Program\n");
	for (i=0; i < 100; i++){
		printf("%d ",A[i] );
	}
	printf("\n");  
}         
   
	