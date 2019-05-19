#include <cstdio>
#include <cstdlib>
#include <iostream>

#define PB(value) (byte *)(value)
using namespace std;
typedef unsigned char byte;
typedef unsigned int dword;

template <class T> void show(const T &value) {
  for (dword i = 0; i < sizeof(T); i++) {
    byte Byte = *(PB(&value) + i);
    for (dword j = 0; j < 8; j++)
      cout << dword((Byte >> (7 - j)) & 1);
    cout << ' ';
  }
  cout << endl;
}

int main() {
  int val1 = 0;
  double val2 = 0;
  char val3 = ' ';
  cout << "Enter int value: ";
  cin >> val1;
  show(val1);
  cout << "Enter double value: ";
  cin >> val2;
  show(val2);
  cout << "Enter char value: ";
  scanf("%d", val3);
  show(val3);

  return 0;
}
