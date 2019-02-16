#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define N 100
#define T 4
int main() {
	int i;
	int lim=500;
	int count=0;     
	int A[100];      
	srand(1234);     /* Set random seed */      
	for (i=0; i < 100; i++){
		A[i] = rand()%1000;   /* Set each element randomly to 0-999 */ 
	}
	#pragma omp parallel for shared(count)
	for (i=0;i<100;i++)
		if (A[i]>=lim){
			#pragma omp critical
			count++;
		}
	printf("Parallel Program\n");
	printf("Total less than or eq 500 : %d\n",count);
}         
   
	