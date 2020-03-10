#include "omp.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// TODOS OS VALORES PRIMOS DE 0 A N
void main()
{
    int const l = 100;
    int vet[100];
    for (int i = 1; i < l; i += 2)
    {
        vet[i] = i;
    }

#pragma omp parallel for
    for (int i = 0; i < l; i++)
    {
        if (vet[i] % 3 == 0 && vet[i] != 3)
        {
            vet[i] = -1;
        }
        if (vet[i] % 5 == 0 && vet[i] != 5)
        {
            vet[i] = -1;
        }
        if (vet[i] % 7 == 0 && vet[i] != 7)
        {
            vet[i] = -1;
        }
    }
    
    for (int i = 0; i < l; i++)
    {
        if (vet[i] != -1 && vet[i] > 0)
        {
            printf("%d ", vet[i]);
        }
    }
}
