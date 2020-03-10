#include "omp.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int l, div, d, x;
    l = 100;
    printf("Os numeros primos entre 1 e o %d sao: 1 ", l);

    #pragma omp parallel for
    for (div = 3; div <= l; div += 2)
    {
        x = 0;
        for (d = 3; d <= l; d += 2)
        {
            if (div % d == 0)
            {
                x = x + 1;
            }
        }
        if (x == 1)
        {
            printf("%d ", div);
        }
    }

    return 0;
}
