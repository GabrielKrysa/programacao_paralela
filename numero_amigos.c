#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
#include <math.h>

int main()
{
    const int N = 50000;
	double parallel[N];

	#pragma omp parallel
	{
		for (int i = 1; i < N; i++)
		{
            int sum = 0;
            for(int j = 1; j <= i;j++)
            {
                if(i % j == 0)
                {
                    sum += j;    
                }
            }

            parallel[i] = (double) sum / i;
		}
	}

    for(int k = 1; k < N; k++){
            for(int l = 1; l < k; l++){
                if(parallel[k] == parallel[l] && k != l){
                    printf("%d eh amigo de %d\n",k,l);
                }
            }
        }
    return 0;
}
