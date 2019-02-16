#include <stdio.h>
#include <stdlib.h>
int main() {
	int i;
	int max_val=0;     
	int A[100];      
	srand(1234);     /* Set random seed */      
	for (i=0; i < 100; i++){
		A[i] = rand()%1000;   /* Set each element randomly to 0-999 */ 
	}
	printf("Sequential Program\n"); 		
	for (i=0; i < 100; i++){
		if (A[i]>max_val)
			max_val=A[i];
	} 
	printf("%d\n",max_val); 
}         
   