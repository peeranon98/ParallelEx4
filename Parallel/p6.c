#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int num_steps = 1000000;
double step,pi;
int main() {
	int T=1;
	printf("Thread: ");
	scanf("%d",&T);
	double st = omp_get_wtime();
	int i;
	double x,sum=0.0;
	step = 1.0/(double) num_steps; 

	#pragma omp parallel private(x) reduction(+:sum)
	{
		int chunkSize = num_steps/T;
		int tid = omp_get_thread_num();
		int start = tid*chunkSize;
		int end = (tid+1)*chunkSize-1;
		for (i=0;i<num_steps;i++){
			x=(i+0.5)*step;
			sum = sum + 4.0/(1.0+x*x);
		}
	}
	pi = step*sum;
	printf(" Pi %.10f\n",pi);
	double et = omp_get_wtime();
	double tt = et-st;
	printf("Execution time = %f seconds.\n",tt);
}         
   
	