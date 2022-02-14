#include <stdio.h>
#include <math.h>
#include <malloc.h>
#define N 10000000
#define M_PI 3.14159265


int main() {
	double *arr = (double*)malloc(N * sizeof(double));
	double total = 0;
#pragma acc data copyin(arr) copyout(total)
	{
#pragma acc kernels
		{
			for (long int i = 0; i < N; ++i){
				arr[i] = sin((2 * M_PI) / N * i);
				total += arr[i];
			}
		}
	}
	printf("%e", total);

	return 0;
}