#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	int data;
	struct node *next;
}*Node;

Node pre = NULL;

Node getNode(int data)
{
	Node nnode = NULL;

	nnode = (Node)malloc(sizeof(struct node));
	nnode->next = NULL;
	nnode->data = data;

	return nnode;
}

Node insert(Node head,Node nnode)
{
	if(head == NULL)
		return nnode;
	
	head->next = insert(head->next,nnode);

	return head;
}

Node reverse(Node head)
{
	if(head->next == NULL || head == NULL)
		return head;
		
	Node temp = reverse(head->next);
	head->next->next = head;
	head->next = NULL;

	return temp;
}

void rev(Node Head)
{
	Node temp = Head->next;
	Head->next = pre;
	pre = Head;
	Head = temp;
	if(Head)
		rev(Head);
}

void print(Node head)
{
	if(head == NULL)
		return;	

	printf("%d ",head->data);
	print(head->next);
}

void main(int argc,char *argv[])
{
	int num,i;
	Node head = NULL;
	if(argc!=2)
	{
		printf("two arguments in commandline you asshole :|\n");
		exit(0);
	}
	num = atoi(argv[1]);

	for(i=0;i<num;i++)
	{
		Node nnode = getNode(random()%100);
		head = insert(head,nnode);
	}
	printf("\nBefore reverse:");
	print(head);
	rev(head);
	printf("\nAfter reverse: ");
	print(pre);
	printf("\n");
}









