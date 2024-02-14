#include <omp.h>
#include <stdio.h>
#define ARR_SIZE 1000000000
static int a[ARR_SIZE];
int main(int *argc, char *argv[])
{
	int i, sum = 0;
	double t1, t2;
	/*Initialize the array*/
	
	for(i =0; i<ARR_SIZE; i++){
		a[i] = 1;
	}
	
	t1 = omp_get_wtime();
	//sum up the array
	
	for(i=0;i<ARR_SIZE;i++)
		sum+=a[i];
	
	t2 = omp_get_wtime();
	printf("Time taken : %g for sum : %d \n", t2-t1, sum);
	
	return 0;
}