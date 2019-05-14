#include <stdio.h>
#include <stdlib.h>

#include <time.h>
#define swap(x, y)                                                             \
  {                                                                            \
    int t = x;                                                                 \
    x = y;                                                                     \
    y = t;                                                                     \
  }

#define N 50000

int swaping = 0;
int comparing = 0;

void MinMax(int a[]) {
  int temp, min, max, end, i, j;
  for (i = 0; i < (N / 2); i++) {
    min = a[i], max = a[i];
    min = max = i;
    for (j = i, end = N - i - 1; j <= end; j++)
      if (a[j] < a[min]) {
        min = j;
        comparing++;
      } else if (a[j] > a[max]) {
        max = j;
        comparing++;
      }
    if (i == max) {
      swap(a[end], a[max]);
      swaping++;
      comparing++;
      if (end != min) {
        swap(a[i], a[min]);
        swaping++;
        comparing++;
      }
    } else {
      if (i != min) {
        swap(a[i], a[min]);
        swaping++;
        comparing++;
      }
      if (end != max) {
        swap(a[end], a[max]);
        swaping++;
        comparing++;
      }
    }
  }
}

void Fill(int a[], int isReversOrRand) {
  srand(time(NULL));
  if (isReversOrRand == 0) {
    for (int i = 0; i < N; i++)
      a[i] = i;
  } else if (isReversOrRand == 1) {
    for (int i = 0, k = N - 1; i < N; i++, k--)
      a[i] = k;
  } else {
    for (int i = 0; i < N; i++)
      a[i] = rand() % 10;
  }
}

// void Fill(int a[], char *path) {}

int main() {
  int a[N];

  clock_t start, finish;
  float result;

  Fill(a, 0);
  start = clock();
  MinMax(a);
  finish = clock();
  result = (float)(finish - start) / CLOCKS_PER_SEC;
  printf("Count swaping with sorted array: %i\n", swaping);
  printf("Count comparing: %i\n", comparing);
  printf("Time is: %f\n", result);

  swaping = 0;
  comparing = 0;
  Fill(a, 1);
  // Uncomment it, when show only 10 elem;
  /*for (int i = 0; i < N; i++)
    printf("%i\t", a[i]);
  printf("\n");*/
  start = clock();
  MinMax(a);
  finish = clock();
  result = (float)(finish - start) / CLOCKS_PER_SEC;
  printf("Count swaping with reverse sorted array: %i\n", swaping);
  printf("Count comparing: %i\n", comparing);
  printf("Time is: %f\n", result);
  // Uncomment it, when show only 10 elem;
  /*for (int i = 0; i < N; i++)
    printf("%i\t", a[i]);
  printf("\n");*/

  swaping = 0;
  comparing = 0;
  Fill(a, 2);
  // Uncomment it, when show only 10 elem;
  /*
  for (int i = 0; i < N; i++)
    printf("%i\t", a[i]);
  printf("\n");*/
  start = clock();
  MinMax(a);
  finish = clock();
  result = (float)(finish - start) / CLOCKS_PER_SEC;
  printf("Count swaping with dynamic sorted array: %i\n", swaping);
  printf("Count comparing: %i\n", comparing);
  printf("Time is: %f\n", result);
  // Uncomment it, when show only 10 elem;
  /*for (int i = 0; i < N; i++)
    printf("%i\t", a[i]);
  printf("\n");*/

  return 0;
}
