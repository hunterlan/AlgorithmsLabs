struct Ttree
{
    int value;
    Ttree *l, *r;
    int level;
};

 struct Tstack
{
    Ttree *previous;
    Tstack *next;
};

void Push(Tstack *&top, Ttree *cur) //добавление элемента в стек
{
    Tstack *node = (Tstack*)malloc(sizeof(Tstack));
    node->previous = cur;
    node->next = top;
    top = node;
}

Ttree* Pop(Tstack *&top) //удаление элемента из стека
{
    Ttree* treenode = top->previous;
    Tstack *node;
    if(top)
    {
        node = top;
        top = top->next;
        free(node);
    }
    return treenode;
}

void InOrderIter(Ttree *root, Tstack *&top)//итерационный обход смешанный
{
    bool stop = true;
	Ttree *current = root;
	while(stop)
    {
		while(current != NULL)
        {
            Push(top, current);
			current = current->l;
        }
		if (top==0) stop = false;
		else
		{ 	current = Pop(top);
			for (int i=0; i < current->level; i++)
               printf("   ");
			printf("%d \n", current->value);
			current = current->r;
		}
   }
}

int main() {
    


  return 0;
}
