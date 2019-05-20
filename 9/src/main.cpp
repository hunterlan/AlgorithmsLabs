#include <ctime>
#include <iostream>

using namespace std;

const int SIZE = 10000;
const int SIZE_BAR = SIZE + 1;

static int comparing = 0;

void fillArr(int arr[], size_t size);
int LinearSearchWithBarrier(int arr[], int key);
bool BinSearch(int *arr, int key, int &m);

int main() {
  int arr1[SIZE_BAR];
  fillArr(arr1, SIZE_BAR);
  int index;
  clock_t start, finish;
  start = clock();
  if ((index = LinearSearchWithBarrier(arr1, 501)) == -1) {
    finish = clock();
    cout << "The number isn't found.\n";
    cout << "Time: " << float(finish - start) / CLOCKS_PER_SEC << '\n';
  } else {
    finish = clock();
    cout << "The number on index: " << index << '\n';
    cout << "Time: " << float(finish - start) / CLOCKS_PER_SEC << '\n';
  }

  cout << "Count comparing: " << comparing << "\n";

  comparing = 0;
  int arr2[SIZE];
  fillArr(arr2, SIZE);
  int m = SIZE / 2;
  start = clock();
  if (BinSearch(arr2, 2, m) == false) {
    finish = clock();
    cout << "The number was found\n ";
    cout.precision(2);
    cout << "Time: " << float(finish - start) / CLOCKS_PER_SEC << '\n';
  } else {
    finish = clock();
    cout << "The number isn't found.\n";
    cout.precision(2);
    cout << "Time: " << float(finish - start) / CLOCKS_PER_SEC  << '\n';
  }

  cout << "Count comparing: " << comparing << "\n";

  return 0;
}

void fillArr(int arr[], size_t size) {
  srand(time(NULL));
  for (int i = 0; i < size; i++)
    arr[i] = rand() % 1000;
}

int LinearSearchWithBarrier(int arr[], int key) {
  size_t i = 0;
  arr[SIZE_BAR - 1] = key;
  while (arr[i] != key) {
    i++;
    if (i == SIZE_BAR - 1)
      return -1;
    comparing++;
  }
  return i;
}

bool BinSearch(int *arr, int key, int &m) {
  int b = 0, e = SIZE; // начальные значения границ
  bool notFound = true;
  while (b <= e && notFound) //пока интервал не сузится до 0
  {
    m = (b + e) / 2; //середина интервала
    if (arr[m] < key)
      {
        comparing++;
        b = m + 1;
      } //поиск в правой части массива
    else if (arr[m] > key)
    {
      comparing++;
      e = m - 1;
    } //иначе - в левой части
    else
      notFound = false; // поиск состоялся
  }
  return notFound;
}
