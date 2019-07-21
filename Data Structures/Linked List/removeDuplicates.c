#include<stdio.h>
#include<stdlib.h>

int HASH[100];

typedef struct node
{
	int data;
	struct node *next;
}*Node;

Node createNode(int data)
{
	Node nnode;
	nnode = (Node)malloc(sizeof(struct node));
	nnode->data = data;
	nnode->next = NULL;

	return nnode;
}

void print(Node Head)
{
	if(Head == NULL)
		return;

	printf("%d ",Head->data);
	print(Head->next);
}

Node insert(Node head,Node nnode)
{
	if(head == NULL)
		return nnode;

	nnode->next = head;
	head = nnode;

	return head;
}

Node removeDup(Node Head)
{
	Node head = Head;
	Node previous = head;
	Node temp,next;

	while(head!=NULL)
	{
		if(HASH[head->data] == 1)
		{
			temp = head;
			next = head->next;
			previous->next = next;
			head = next;
			free(temp);
		}
		else
		{
			HASH[head->data] = 1;
			previous = head;
			head = head->next;
		}
	}
	return Head; 
}

int main()
{
	Node Head = NULL;

	Head = insert(Head,createNode(10));
	Head = insert(Head,createNode(11));
	Head = insert(Head,createNode(10));
	Head = insert(Head,createNode(12));
	Head = insert(Head,createNode(10));
	Head = insert(Head,createNode(10));
	Head = insert(Head,createNode(17));
	Head = insert(Head,createNode(10));
	Head = insert(Head,createNode(17));
	Head = insert(Head,createNode(19));
	Head = insert(Head,createNode(14));

	print(Head);

	Head = removeDup(Head);
	printf("\n");
	print(Head);

	return 0;
}