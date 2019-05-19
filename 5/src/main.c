#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 6
int NewIndex(int x, int y) //пересчет индексов
{
  int j = 0;
  for (int i = 0; i < x; i++)
    j += N - i;
  return j + y - x;
}
void Put(int vec[], int x, int y, int v) // Запись в вектор (сжатие)
{
  if (y >= x)
    vec[NewIndex(x, y)] = v;
}
int Get(int vec[], int x, int y) // Чтение из вектора
{
  if (y >= x)
    return vec[NewIndex(x, y)];
  else
    return 0;
}
void RandArray(int a[N][N]) //формирование исходного массива
{
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      if (j >= i)
        a[i][j] = rand() % 50;
      else
        a[i][j] = 0;
}

void PrintArray(int a[N][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++)
      printf("%3i", a[i][j]);
    printf("\n");
  }
}

int main() {
  int vec[N * N / 2 + N / 2];
  int array[N][N];
  RandArray(array);
  clock_t start, finish;
  start = clock();
  PrintArray(array);
  finish = clock();
  // printf("Result is: %f\n", float(finish - start) / CLOCKS_PER_SEC);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      Put(vec, i, j, array[i][j]); //сжатие массива
  printf("\n");
  start = clock();
  for (int i = 0; i < N * N / 2 + N / 2; i++) //выдача результата сжатия
    printf("%3i", vec[i]);
  printf("\n\n");
  finish = clock();
  // printf("Result is: %f\n", float(finish - start) / CLOCKS_PER_SEC);
  start = clock();
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) //чтение из сжатого представления
      printf("%3i", Get(vec, i, j));
    printf("\n");
  }
  finish = clock();
  // printf("Result is: %f\n", float(finish - start) / CLOCKS_PER_SEC);
  return 0;
}
