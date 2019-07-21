#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}*Node;

Node createNode(int data)
{
	Node temp = NULL;
	temp = (Node)malloc(sizeof(struct node));
	temp->next  = NULL;
	temp->data = data;

	return temp;
}

Node insert(Node Head,Node nnode)
{
	if(!Head)
		return nnode;
	
	Head->next = insert(Head->next,nnode);
	
	return Head;
}


void print(Node Head)
{
	if(!Head)
	{
		printf("\n");
		return;
	}
	printf("%d ",Head->data);
	print(Head->next);
}

Node merge(Node h1,Node h2)
{
	if(!h1)
		return h2;
	if(!h2)
		return h1;

	Node res = NULL;

	if(h1->data >= h2->data)
	{
		res = h2;
		res->next = merge(h1,h2->next);
	}
	else
	{
		res = h1;
		res->next = merge(h1->next,h2);
	}

	return res;

}

int main()
{
	Node Head,Head1,Head2;
	Head1 = Head2 = Head = NULL;
	int ele;

	printf("\nEnter the elements of first list list: in sorted order");
	for(int i=0;i<10;i++)
	{
		scanf("%d",&ele);
		Head1 = insert(Head1,createNode(ele));
	}

	printf("\nEnter the elements of the second list in sorted order: ");
	for(int i=0;i<5;i++)
	{
		scanf("%d",&ele);
		Head2 = insert(Head2,createNode(ele));
	}

	Head = merge(Head1,Head2);

	print(Head1);
	print(Head2);
	print(Head);

	return 0;
}
