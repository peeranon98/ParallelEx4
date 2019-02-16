#include <stdio.h>
#include <stdlib.h>
int main() {
	int i;     
	int A[100];      
	srand(1234);     /* Set random seed */      
	for (i=0; i < 100; i++){
		A[i] = rand()%1000;   /* Set each element randomly to 0-999 */ 
		A[i] *= 10;
	}
	printf("Sequential Program\n"); 		
	for (i=0; i < 100; i++){
		printf("%d ",A[i]);
	} 
	printf("\n"); 
}         
   
	