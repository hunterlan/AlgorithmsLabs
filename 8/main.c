#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Node of universities. In this node - node of faculties.

//Node Faculties.
struct Faculties{
  char * name; //name of faculti
  struct Faculties * next; //next elem in node.
};

//Node of Universities
struct Universities{
  char * name;//name of university
  struct Faculties * fac;//node of Faculties.
  struct Universities * next;//next elem in node
};

struct Universities * initUn(char * nameUn, struct Faculties * facUn);
struct Universities * addUn(
  struct Universities * universities,
  char * nameUn, struct Faculties * facUn);
struct Universities * delLastUn(struct Universities * universities);
void ShowUn(struct Universities * un);

struct Faculties * delLastFc(struct Faculties * facUn);
struct Faculties * initFc(char * nameFc);
void showFc(struct Faculties * fac);

int main() {
  struct Universities * listUn;
  struct Faculties * facUn;

  facUn = initFc("CIT");
  listUn = initUn("KhPI", facUn);

  listUn = addUn(listUn, "KhNURE", facUn);

  ShowUn(listUn);
  while(listUn)
    listUn = delLastUn(listUn);

  return 0;
}

struct Universities * initUn(char * nameUn, struct Faculties * facUn)
{
  struct Universities * lst;
  lst = (struct Universities*)malloc(sizeof(struct Universities));

  lst->name = nameUn;
  lst->fac = facUn;
  lst->next = NULL;

  return lst;
}

struct Faculties * initFc(char * nameFc)
{
  struct Faculties * lst;
  lst = (struct Faculties*)malloc(sizeof(struct Faculties));

  lst->name = nameFc;
  lst->next = NULL;

  return lst;
}

struct Universities * addUn(struct Universities * universities,
  char * nameUn, struct Faculties * facUn)
{
  struct Universities * temp, *prev;
  temp = (struct Universities *)malloc(sizeof(struct Universities));

  prev = universities->next;
  universities->next = temp;
  temp->name = nameUn;
  temp->fac = facUn;
  temp->next = prev;

  return temp;
}

void showFc(struct Faculties * fac)
{
  printf("Faculties: ");
  while(fac)
  {
    printf("%s ", fac->name);
    fac = fac->next;
  }
  printf("\n");
}

void ShowUn(struct Universities * un)
{
  while(un)
  {
    printf("University: %s\n", un->name);
    showFc(un->fac);
    un = un->next;
  }
  printf("\n");
}

struct Faculties * delLastFc(struct Faculties * facUn)
{
  struct Faculties * temp;
  temp = facUn;
  while(facUn->next)
    facUn = facUn->next;
  if(facUn)
    free(facUn);
  return temp;
}

struct Universities * delLastUn(struct Universities * universities)
{
  struct Universities * temp;
  temp = universities;
  while(universities->next)
    universities = universities->next;
  while(universities->fac->name)
    universities->fac = delLastFc(universities->fac);
  free(universities);
  return temp;
}
