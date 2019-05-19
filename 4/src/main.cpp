#include <iostream>
#include <time.h>
using namespace std;

void BYTE(unsigned char A) // виведення вмісту байта
{
  for (int bit = 128; bit >= 1; bit >>= 1)
    cout << (A & bit ? '1' : '0');
  cout << ' ';
}
struct Office {
  int s; /* 4 bytes */
  short flip1 : 1;
  short flip2 : 1;
  union {
    struct {
      bool b;
      double dl;
    } prim1;
    struct {
      short st;
    } prim2;
  } un;
};
struct Buh {
  short s; /* 4 bytes */
  int flip1 : 4;
  int flip2 : 2;
  int flip3 : 4;
};

int main() {
  Office obj1 = {5, 1, 0, 1, 0};
  obj1.un.prim1.dl = 2.5;
  obj1.un.prim1.b = true;
  unsigned char *p = (unsigned char *)&obj1;
  int byte = 0;
  clock_t start, finish;
  start = clock();
  for (; byte < sizeof(Office); byte++, p++) {
    if (byte && !(byte % 8))
      cout << endl;
    BYTE(*p);
  }
  finish = clock();
  cout << endl;
  cout << endl;
  cout << "The time is: " << float(finish - start) / CLOCKS_PER_SEC << '\n';
  Buh obj2 = {5, 1, 0, 1};
  p = (unsigned char *)&obj2;
  start = clock();
  for (int byte = 0; byte < sizeof(Buh); byte++, p++)
    BYTE(*p);
  finish = clock();
  cout << endl;
  cout << endl;
  cout << "The time is: " << float(finish - start) / CLOCKS_PER_SEC << '\n';

  return 0;
}
