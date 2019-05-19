#include <iostream>

class string {
  char *str;
  unsigned long len;

public:
  string() {
    len = 1;
    str = (char *)malloc(len * sizeof(char));
  }

  unsigned long GetSize() { return this->len - 1; }

  char *GetStr() { return this->str; }

  void SetStr(char *str1) {
    for (int i = 0; str1[i] != '\0'; i++)
      this->len++;
    this->str = (char *)realloc(this->str, len);
    for (int i = 0; i < len - 1; i++)
      str[i] = str1[i];
  }
};

int strcmp(string str1, string str2) {
  if (str1.GetSize() < str2.GetSize())
    return -1;
  else if (str1.GetSize() > str2.GetSize())
    return 1;
  for (int i = 0; i < str1.GetSize() - 1; i++) {
    if (str1.GetStr()[i] < str2.GetStr()[i])
      return -1;
    else if (str1.GetStr()[i] > str2.GetStr()[i])
      return 1;
  }

  return 0;
}

int main() {
  char tmp1[] = "Hello";
  string str1;
  string str2;
  str1.SetStr(tmp1);
  std::cout << "The size of str1 is: " << str1.GetSize() << '\n';
  str2.SetStr(tmp1);
  std::cout << "The size of str2 is: " << str2.GetSize() << '\n';
  if (strcmp(str1, str2) == 0)
    std::cout << "This strings is equal.\n";

  return 0;
}
