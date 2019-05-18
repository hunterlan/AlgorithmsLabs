#include <stdlib.h>
#include <stdio.h>

struct node // структура для представления узлов дерева
{
	int key;
	unsigned char height;
	struct node* left;
	struct node* right;
};

unsigned char Height(struct node* p)
{
	return p? p->height : 0;
}

int Bfactor(struct node* p)
{
	return Height(p->right) - Height(p->left);
}

void FixHeight(struct node* p)
{
	unsigned char hl = Height(p->left);
	unsigned char hr = Height(p->right);
	p->height = (hl > hr? hl : hr)+1;
}

struct node* RotateRight(struct node* p) // правый поворот вокруг p
{
  struct node* q = p->left;
	p->left = q->right;
	q->right = p;
	FixHeight(p);
	FixHeight(q);
	return q;
}

struct node* RotateLeft(struct node* q) // левый поворот вокруг q
{
  struct node* p = q->right;
	q->right = p->left;
	p->left = q;
	FixHeight(q);
	FixHeight(p);
	return p;
}

struct node* Balance(struct node* p) // балансировка узла p
{	FixHeight(p);
	if( Bfactor(p)==2 )
	{	if( Bfactor(p->right) < 0 )
			p->right = RotateRight(p->right);
		return RotateLeft(p);
	}
	if( Bfactor(p)==-2 )
	{	if( Bfactor(p->left) > 0  )
			p->left = RotateLeft(p->left);
		return RotateRight(p);
	}
	return p; // балансировка не нужна
}

struct node* Insert(struct node* p, int k) // вставка ключа k в дерево с корнем p
{
  if( !p )
	{
    p = (struct node *)malloc(sizeof(struct node));
		p->key = k; p->left = p->right = 0; p->height = 1;
		return p;
	}
	if( k<p->key )
		p->left = Insert(p->left,k);
	else
		p->right = Insert(p->right,k);
	return Balance(p);
}

struct node* FindMin(struct node* p) // поиск узла с минимальным ключом в дереве p
{
  if(p->left == NULL)
    return p;
  return FindMin(p->left);
}

struct node* FindMax(struct node* p) // поиск узла с минимальным ключом в дереве p
{
  if(p->right == NULL)
    return p;
  return FindMax(p->right);
}


void Print(struct node *tree, int level)
{	int i;
	if (tree == NULL)  return;
	Print(tree->left, level - 2);
	for (i = 0; i < level; i++)
		printf(" ");
	printf("%d\n", tree->key);
	Print(tree->right, level - 2);
}

void Delete(struct node *tree)  //удаление дерева
{
  if (tree == NULL) return;
	Delete(tree->left);
	Delete(tree->right);
	free(tree);
}

int main()
{
  struct node *tree = NULL;
	tree = Insert(tree, 10);    //построение дерева
	tree = Insert(tree, 5);
	tree = Insert(tree, 3);
	tree = Insert(tree, 1);
	tree = Insert(tree, 2);
	tree = Insert(tree, 11);
	tree = Insert(tree, 12);
	tree = Insert(tree, 15);
	tree = Insert(tree, 18);
	//Print(tree, 30);
	printf("\n\n");
  struct node *min = FindMin(tree);
  struct node *max = FindMax(tree);
  printf("The min is: %d\n", min->key);
  printf("The max is: %d\n", max->key);
	//Remove(tree, 10);
	//Remove(tree, 11);
	//Print(tree, 30);
  Delete(min);
  Delete(max);
	Delete(tree);
	return 0;
}
