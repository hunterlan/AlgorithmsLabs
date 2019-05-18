///
#include <iostream>
#include <time.h>

#define N 100
#define M 50

struct Cities {
  unsigned int index;
  char name[8];
  size_t amount_of_citizen;
  size_t square;
};

Cities state[N];

struct HashTAB {
  int key;
  HashTAB *next;
  int adress;
};

HashTAB HT[M];

int Hashing(int key) { return (key % M); }

void Init() {
  for (int i = 0; i < M; ++i) {
    HT[i].next = nullptr;
  }
}

int Search(int x) {
  int key = Hashing(x);
  HashTAB *temp;
  temp = HT[key].next;
  if (!temp)
    return -1;
  while ((temp->next) && (temp->key != x))
    temp = temp->next;
  if (temp->key != x)
    return -1;

  return temp->adress;
}

void Insert(int x, int i) {
  int key = Hashing(x);
  HashTAB *temp = new HashTAB;
  temp->next = nullptr;
  temp->key = x;
  // if (!HT[key]) HT[key]->next = temp;
  // else {
  temp->next = HT[key].next;
  HT[key].next = temp;
  temp->adress = i;
  //  }
}

void PrintH() {
  for (int i = 0; i < M; ++i) {
    auto temp = HT[i].next;
    std::cout << i;

    if (HT[i].key)
      std::cout << HT[i].key;
    if (temp)
      while (temp)
        std::cout << "->" << temp->key, temp = temp->next;
    std::cout << std::endl;
  }
}

int InterpolSearch(Cities arr[], int key) {
  int m, b = 0, e = N - 1;
  while (b <= e && arr[b].index <= key && arr[e].index >= key) {
    m = b + ((key - arr[b].index) * (e - b)) / (arr[e].index - arr[b].index);
    if (arr[m].index < key)
      b = m + 1;
    else if (arr[m].index > key)
      e = m - 1;
    else
      return m;
  }
  if (arr[b].index == key)
    return b;
  else
    return -1;
}

int main() {
  Init();
  for (int i = 0; i < N; ++i) {
    state[i].name[0] = rand() % 25 + 90;
    state[i].name[1] = rand() % 25 + 90;
    state[i].name[2] = rand() % 25 + 90;
    state[i].name[3] = rand() % 25 + 90;
    state[i].name[4] = rand() % 25 + 90;
    state[i].name[5] = rand() % 25 + 90;
    state[i].name[6] = '\000';
    state[i].amount_of_citizen = random();
    // state[i].index = rand() % 10000;
    state[i].index = i;
    state[i].square = random() % 1234567890;
    Insert(state[i].index, i);
  }
  PrintH();

  state[N - 1].index = 111111;
  Insert(state[N - 1].index, N - 1);
  auto b = InterpolSearch(state, N - 1);
  auto a = Search(state[N - 1].index);
  if (a != -1)
    std::cout << '\n'
              << state[a].index << ' ' << state[a].name << ' '
              << state[a].amount_of_citizen << std::endl;
}
