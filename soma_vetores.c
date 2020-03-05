#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int N = 10;
  int arr1[N], arr2[N];
  srand(time(NULL));

  for (int i = 0; i < N; i++) {
    arr1[i] = rand() % 2;
    arr2[i] = rand() % 2;
  }
    int arraResult[N];
  #pragma omp parallel
  {
    int x = omp_get_num_threads();//total de threds

    #pragma omp for
    for(int i = 0; i < N; i++){
        arraResult[i] = arr1[i] + arr2[i];
    }
  }

  for (int i = 0; i < N; i++) {
    printf("%d\n",arraResult[i]);
  }

  return 0;
}
