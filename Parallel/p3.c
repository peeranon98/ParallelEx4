#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define N 100
#define T 4
int main() {
	int i;
	int max_val;     
	int A[100];      
	srand(1234);     /* Set random seed */      
	for (i=0; i < 100; i++){
		A[i] = rand()%1000;   /* Set each element randomly to 0-999 */ 
	}
	#pragma omp parallel for reduction (max:max_val)
	for (i=0;i<100;i++)
		max_val = max_val > A[i] ? max_val : A[i];
	printf("Parallel Program\n");
	printf("%d\n",max_val);
}         
   
	