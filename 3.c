#include <omp.h>
#include <stdio.h>
#define ARR_SIZE 1000000000
static int a[ARR_SIZE];

int main(int *argc, char *argv[])
{
	int i, sum = 0;
	int tid, numt = 0;
	double t1, t2;
	
	/*Initialize the array*/
	for(i =0; i<ARR_SIZE; i++)
		a[i] = 1;
	
	t1 = omp_get_wtime();
	
	// sum up the array
	#pragma omp parallel default(shared) private( i, tid )
	{
		int top, end; 
		int subTotal = 0;
		
		tid = omp_get_thread_num();
		numt = omp_get_num_threads();
		
		top = (ARR_SIZE / numt) * tid;
		end = (ARR_SIZE / numt) * (tid + 1);
		
		// For the final process, the last array index is used
		if(tid == numt - 1)
			end = ARR_SIZE;
		
		for(i = top; i < end; i++)
			subTotal += a[i];
		
		#pragma omp critical
		sum += subTotal;
	}
	
	t2 = omp_get_wtime();
	
	printf("Number of threads : %d\n", numt);
	printf("Time taken : %g for sum : %d \n", t2-t1, sum);
	return 0;
}