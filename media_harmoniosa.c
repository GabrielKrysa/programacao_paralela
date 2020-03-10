#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
#include <math.h>

int main()
{
	int a[3] = {1,2,4};
	double b = 0.0;
	
	#pragma omp parallel
	{
		#pragma omp for reduction(+:b)
		for (int i = 0; i < 3; i++)
		{
			b += (1.0/a[i]);
		}
	}
	double c = (3/b);
	printf("%.2f\n", c);

    return 0;
}
