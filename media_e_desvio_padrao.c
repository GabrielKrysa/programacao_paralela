#include <math.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int N = 10;
  int arr1[N];
  double desvio;
  double avg;
  int sum = 0;

  for (int i = 0; i < N; i++) {
    scanf("%d", &arr1[i]);
  }
  
  double result = 0;

  #pragma omp parallel
  {
    #pragma omp for reduction (+:result)
    for (int i = 0; i < N; i++) {
      result += arr1[i];
    }
  }

  avg = result / N;
 
  #pragma omp parallel
  {
    #pragma  omp for reduction (+:sum)
    for (int i = 0; i < N; i++) {
      sum += (arr1[i] - avg) * (arr1[i] - avg);
    }
  }

  desvio = sqrt(sum / N);
 
  printf("Desvio: %lf\n", desvio);
  printf("Media: %lf\n", avg);
  return 0; 
}
