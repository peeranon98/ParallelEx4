#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define N 100
#define T 4
int main() {
	int i;
	int sum=0;     
	int A[100];      
	srand(1234);     /* Set random seed */      
	for (i=0; i < 100; i++){
		A[i] = rand()%1000;   /* Set each element randomly to 0-999 */ 
	}
	#pragma omp parallel for reduction (+:sum)
	for (i=0;i<100;i++)
		sum += A[i];
	printf("Parallel Program\n");
	printf("%d\n",sum);
}         
   
	