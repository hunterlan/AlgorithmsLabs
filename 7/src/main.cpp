#include <iostream>

using namespace std;

int och[512];  //черга на 512 запитів
int point = 0; //вказівник кінець черги

int AddEl(int a) //додавання запиту у чергу
{
  if (point < 512)
    och[point++] = a;
  else {
    cout << "Queue is full\n"; //черга переповнена
    return 0;
  }
  return 1;
}
void DelEl(void) //читання запиту з черги
{
  if (point > 0) {
    int max = och[0], nmax = 0; // пошук запиту з max параметром
    for (int i = 1; i < point; i++)
      if (max < och[i])
        max = och[i], nmax = i;
    cout << "Read   " << max << endl;
    point--; //зсув черги
    for (int i = nmax; i < point; i++)
      och[i] = och[i + 1];
  }
}
void PrintOch(void) //видача вмісту черги
{
  if (point == 0)
    cout << "Queue empty \n";
  else {
    cout << "In queue:   ";
    for (int i = 0; i < point; i++)
      cout << och[i] << " ";
    cout << "\n";
  }
}
int main() {
  int op, f;
  do {
    op = rand() % 2; // 0-запис запиту, 1- читання
    cout << "Enquiry " << op << "\n";
    if (op)
      DelEl();
    else {
      f = rand() % 15;
      if (!AddEl(f))
        exit(1);
    }
    PrintOch();
    char s;
    cin >> s;
  } while (1);

  return 0;
}
