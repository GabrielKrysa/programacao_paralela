#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
#include <math.h>

int main()
{
	int numeros[5] = {1,2,3,4,5};
    int maior = INT8_MAX / 2;
    int menor = INT8_MAX / 2 * -1;

    #pragma omp parallel
    {
        //usar reduction com min:max
        #pragma omp for
        for (int i = 0; i < 5; i++)
        {
            //Não sei se precisa fazer algo nesses if's
            if(numeros[i] > maior)
            {
                maior = numeros[i];
            }
            if(numeros[i] < menor)
            {
                menor = numeros[i];
            }
        }
    }
    printf("Maior: %d\tMenor: %d\n", maior, menor);

    return 0;
}
