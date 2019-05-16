// sorting Hoara, sorting partly sorted tree, sorting pair merging
#include <stdio.h>
#include <stdlib.h>

#include <time.h>
#define swap(x, y)                                                             \
  {                                                                            \
    int t = x;                                                                 \
    x = y;                                                                     \
    y = t;                                                                     \
  }

#define N 10

int swaping = 0;
int comparing = 0;

void Surface(int a[], int i, int k) {
  int j, m = 2 * i, temp = a[i];
  while (m <= k) {
    if (m == k) {
      j = m;
      comparing++;
    } else if (a[m] > a[m + 1]) {
      j = m;
      comparing++;
    } else {
      j = m + 1;
    }
    if (a[j] > temp) {
      a[i] = a[j];
      i = j;
      m = 2 * i;
      comparing++;
    } else
      break;
  }
  a[i] = temp;
}
//Сортировка вектора методом Флойда
void TreeSort(int a[]) {
  int i, k, w;
  for (i = N / 2; i >= 0; i--)
    Surface(a, i, N);
  for (k = N - 1; k >= 0; k--) {
    Surface(a, 0, k);
    swap(a[k], a[0]);
    swaping++;
  }
}

void HoaraSort(int a[], int b, int e) {
  int i = b;
  int j = e;
  int tmp = 0;
  int x = a[(i + j) / 2];
  do {
    while (a[i] < x)
      i++;
    while (a[j] > x)
      j--;
    if (i <= j) {
      swaping++;
      comparing++;
      swap(a[i], a[j]);
      i++;
      j--;
    }
  } while (i <= j);
  if (i < e)
    {
      comparing++;
      HoaraSort(a, i, e);
    }
  if (b < j)
    {
      comparing++;
      HoaraSort(a, b, j);
    }
}

void PairMergeSort(int a[]) {
  int i0, j0, i, j, si, sj, k, ke, t, m;
  si = 1; // начальный размер одного множества
  while (si < N) //цикл пока одно множество не составит весь массив}
  {
    i0 = 0; // нач. индекс 1-го множества пары
    while (i0 < N) // цикл пока не пересмотрим весь массив
    {
      j0 = i0 + si; // нач. индекс 2-го множества пары
      i = i0;
      j = j0;
      //размер 2-го множества пары может ограничиваться концом массива
      if (si >= N - j0)
        sj = N - j0;
      else
        sj = si;
      if (sj > 0) {
        comparing++;
        k = i0; // нач. индекс слитого множества
        while ((i < i0 + si + sj) &&
               (j < j0 + sj)) // цикл пока не исчерпаются оба входные множества
        {
          if (a[i] > a[j])
          // если эл-т 1-го <= элемента 2-го, он остается на своем месте, но
          // вых.множество расширяется иначе - освобождается место в
          // вых.множестве и туда  заносится эл-т из 2-го множества
          {
            comparing++;
            t = a[j];
            for (m = j - 1; m >= k; m--)
              a[m + 1] = a[m];
            a[k] = t;
            j++; //к след. эл-ту во 2-м множестве
          }
          k++; // вых. множество увеличилось
          i++; // если был перенос - за счет сдвига, если не было - за счет
               // перехода эл-та в вых.
        }
      }
      i0 += si * 2; // начало следующей пары
    }
    si *= 2; // размер эл-тов пары увеличивается вдвое
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

int main() {

  int a[N];

  clock_t start, finish;
  float result;

  printf("Sorting partly sorted tree\n\n");
  Fill(a, 0);
  start = clock();
  TreeSort(a);
  finish = clock();
  result = (float)(finish - start) / CLOCKS_PER_SEC;
  printf("Count swaping with sorted array: %i\n", swaping);
  printf("Count comparing: %i\n", comparing);
  printf("Time is: %f\n\n", result);

  swaping = 0;
  comparing = 0;
  Fill(a, 1);
  start = clock();
  TreeSort(a);
  finish = clock();
  result = (float)(finish - start) / CLOCKS_PER_SEC;
  printf("Count swaping with reversed sorted array: %i\n", swaping);
  printf("Count comparing: %i\n", comparing);
  printf("Time is: %f\n\n", result);

  swaping = 0;
  comparing = 0;
  Fill(a, 2);
  start = clock();
  TreeSort(a);
  finish = clock();
  result = (float)(finish - start) / CLOCKS_PER_SEC;
  printf("Count swaping with random data: %i\n", swaping);
  printf("Count comparing: %i\n", comparing);
  printf("Time is: %f\n\n", result);

  printf("Sorting Hoara\n\n");
  swaping = 0;
  comparing = 0;

  Fill(a, 0);
  start = clock();
  HoaraSort(a, 0, N-1);
  finish = clock();
  result = (float)(finish - start) / CLOCKS_PER_SEC;
  printf("Count swaping with sorted array: %i\n", swaping);
  printf("Count comparing: %i\n", comparing);
  printf("Time is: %f\n\n", result);

  swaping = 0;
  comparing = 0;
  Fill(a, 1);
  start = clock();
  HoaraSort(a, 0, N-1);
  finish = clock();
  result = (float)(finish - start) / CLOCKS_PER_SEC;
  printf("Count swaping with reversed sorted array: %i\n", swaping);
  printf("Count comparing: %i\n", comparing);
  printf("Time is: %f\n\n", result);

  swaping = 0;
  comparing = 0;
  Fill(a, 2);
  start = clock();
  HoaraSort(a, 0, N-1);
  finish = clock();
  result = (float)(finish - start) / CLOCKS_PER_SEC;
  printf("Count swaping with random data: %i\n", swaping);
  printf("Count comparing: %i\n", comparing);
  printf("Time is: %f\n\n", result);

  printf("Pair merge sorting\n\n");
  swaping = 0;
  comparing = 0;

  Fill(a, 0);
  start = clock();
  PairMergeSort(a);
  finish = clock();
  result = (float)(finish - start) / CLOCKS_PER_SEC;
  printf("Count swaping with sorted array: %i\n", swaping);
  printf("Count comparing: %i\n", comparing);
  printf("Time is: %f\n\n", result);

  swaping = 0;
  comparing = 0;
  Fill(a, 1);
  start = clock();
  PairMergeSort(a);
  finish = clock();
  result = (float)(finish - start) / CLOCKS_PER_SEC;
  printf("Count swaping with reversed sorted array: %i\n", swaping);
  printf("Count comparing: %i\n", comparing);
  printf("Time is: %f\n\n", result);

  swaping = 0;
  comparing = 0;
  Fill(a, 2);
  start = clock();
  PairMergeSort(a);
  finish = clock();
  result = (float)(finish - start) / CLOCKS_PER_SEC;
  printf("Count swaping with random data: %i\n", swaping);
  printf("Count comparing: %i\n", comparing);
  printf("Time is: %f\n\n", result);

  return 0;
}
