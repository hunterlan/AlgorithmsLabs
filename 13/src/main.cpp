#include<conio.h>
#include<stdlib.h>
#include<iostream>
 using namespace std;

class CtreeNode
{	int key;				//ключ
	int info;			//информационное поле
	CtreeNode *LLink, *RLink; //указатель на левый и правый узел
public:
	CtreeNode(){key=0;LLink=RLink=NULL;} //конструктор по умолчанию
	CtreeNode(int k, int info_c)	     //конструктор с параметр
	{   key=k;
	    info=info_c;
		LLink=RLink=NULL;
	}
	~CtreeNode()			//Деструктор
	{
	}
  //функция добавления элемента в дерево. Возвращает указатель на корень
    void Insert(int number, int info, CtreeNode *ptr);
    void FindMax()
    void PrintTree(CtreeNode *ptr, int n);
	void DeleteTree(CtreeNode *ptr);
};
void CtreeNode::Insert(int n, int inf, CtreeNode *ptr)
{	cout<<"\n Добавляется элемент ("<<n<<";"<<inf<<")\n";
	int flag=1;
	CtreeNode *p, *q;
	p=ptr;
	while(flag)
	{ if(n < p->key)
	  { q=p->LLink;	 //a3
	    cout<<"Найден узел "<<p->key<<endl<<"Переход влево";
	    if(q==NULL)  cout<<"NULL"<<endl;
	    else cout<<q->key<<endl;
	    if(q == NULL)
	    {	flag=0;
		cout<<"Создается новый элемент ("<<n<<","<<inf<<")\n";
		q=new CtreeNode(n,inf);
		cout<<"Обновление связей: "<<p->key<<"->LLink = "<<q->key<<endl;
		p->LLink=q;
	    } else p=q;
	  }
	  else if(n > p->key)
	  {  q=p->RLink;		 //a4
	     cout<<"Найден узел "<<p->key<<endl<<"Переход вправо";
	     if(q == NULL)cout<<"NULL"<<endl;
	     else cout<<q->key<<endl;
	     if(q == NULL)
	     {  flag=0;
		cout<<"Создается новый элемент ("<<n<<","<<inf<<")\n ";
		q=new CtreeNode(n,inf);
		cout<<"Обновление связей: "<<p->key<<"->RLink = "<<q->key<<endl;
		p->RLink=q;
	    }
		else p=q;
	 }
	 else if(n == p->key)
	 {	cout<<"Такой элемент уже существует "<<endl;
		flag=0;//выход из цикла WHILE
	 }
  }
}
  void FindMax::PrintTree()
  {
    if (root) Push(top, root);						//если дерево не пустое - запись в стек
	tree *current = root;
 	while(top)
    {	current = Pop(top);							//чтение из стека
	while(current != NULL)
         {	for (int i=0; i < current->level; i++)   // обработка узла
                    printf("   ");
           printf("%d \n", current->value);
	 if (current->r) Push(top, current->r);	// если есть правая ветвь, запись в стек
	 current = current->l;						// спуск по левой ветви
        }
    }
  }
  void CtreeNode:: PrintTree(CtreeNode *ptr, int n)
  {	if (ptr)
	{   PrintTree(ptr->RLink, n+3);
	    for(int i=1;i<n;i++)
		cout << " ";
		cout<< ptr->key<<endl;
	     PrintTree(ptr->LLink, n+3);
	}
  }
  void CtreeNode::DeleteTree(CtreeNode *ptr)
  { if (ptr != NULL)
	  {   DeleteTree(ptr->LLink);
	      DeleteTree(ptr->RLink);
		  delete(ptr);
	  }
}

void main()		//главная программа
{
	setlocale(LC_ALL, "Rus"); // для работи з кирилицей
	int k_elem;
	char rand_elem;
	cout<<"  Сколько элементов добавлять?  ";
	cin>>k_elem;
	cout<<"  Генерировать случайные элементы? (y/n) ";
	cin>>rand_elem;
	int num,inf;
	if(rand_elem == 'n')
	{   cout<<endl<<"Индекс: ";	//вводить с клавиатуры
	    cin>>num;
	    cout<<"Значение: ";
	    cin>>inf;
	}
        else
        {    num=rand() % 100 + 1;//случайные значения
             inf=rand() % 100 + 1;
        }
	CtreeNode *root=new CtreeNode(num,inf);	//указатель на корень
  	for(int tr_i=1;tr_i<k_elem;tr_i++)
	{ if(rand_elem == 'n')
	  {	cout<<endl<<"Индекс: ";	//вводить с клавиатуры
	        cin>>num;
		cout<<"Значение: ";
		cin>>inf;
	   }
	   else
	   {    num=rand() % 100 + 1;//случайные значения
	        inf=rand() % 100 + 1;
	   }
	   root->Insert(num,inf,root);
  }
	root->PrintTree(root, 5);



  root->DeleteTree(root);		//освобождение памяти
}
