#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void FibonachiIter(int n)
{
  int count = 2;
  int sum = 0, num1 = 1, num2 = 1;
  while(count < n)
  {
    sum = num1 + num2;
    num2 = num1;
    num1 = sum;

    printf("%d\t", sum);
    count++;
  }
}

int FibonachiRec(int n)
{
  if (n == 1 || n == 2)
    return 1; // первые 2 числа равны 1
  return FibonachiRec(n - 1) + FibonachiRec(n - 2); // складываем предыдущие 2 числа
}

#define N 40

int main() {
  clock_t start, finish;
  start = clock();
  FibonachiIter(N);
  finish = clock();
  float result = (float) (finish - start) / CLOCKS_PER_SEC;
  printf("\nTime is %.2f\n", result);

  start = clock();
  for (int i = 1; i <= N; i++) // В цикле выводим N чисел Фибоначчи
    printf("%d ", FibonachiRec(i));
  finish = clock();
  result = (float) (finish - start) / CLOCKS_PER_SEC;
  printf("Time is %.2f\n", result);
  return 0;
}
