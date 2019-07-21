#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}*Node;

Node reverse(Node current)
{
	Node previous,next;

	previous = next = NULL;	
	
	while(current!=NULL)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}

	return previous;
}


Node pairwise(Node Head)
{
	if((!Head->next) || !Head)
		return Head;

	Node temp = Head->next;
	Head->next = Head->next->next;
	temp->next = Head;
	Head = temp;

	Head->next->next = pairwise(Head->next->next);

	return Head;
}
Node createNode(int data)
{
	Node nnode = (Node)malloc(sizeof(struct node));
	nnode->next = NULL;
	nnode->data = data;

	return nnode;
}

Node insert(Node nnode,Node head)
{
	if(head == NULL)
		return nnode;

	head->next = insert(nnode,head->next);

	return head;
}

Node delete(Node Head,int key)
{
	Node h,crap,H;
	h = crap = H = NULL;
	if(Head == NULL)
	{
		printf("Element not found\n");
		return NULL;
	}

	if(Head->data == key)
	{
		h = Head->next;
		free(Head);
		return h;
	}

	H = Head;

	while(H->next!=NULL)
	{
		if(H->next->data == key)
		{
			crap = H->next;
			H->next = crap->next;
			free(crap);

			if(H->next == NULL)
				return Head;
		}
		H = H->next;
	}
	return Head;
}

void print(Node Head)
{
	if(Head == NULL)	
		return;
	

	printf("%d ",Head->data);
	print(Head->next);
}

int main(int argc,char *argv[])
{
	int n,true = 1,key;
	char c;
	Node Head = NULL;

	if(argc!=2)
	{
		printf("Format : $./a.out noofelements \n");
		exit(0);
	}

	n = atoi(argv[1]);

	for(int i=0;i<n;i++)
		Head = insert(createNode(rand()%100),Head);

	print(Head);

	printf("\n");

	Head = pairwise(Head);
	//Head = reverse(Head);
	print(Head);
	
	return 0;
}
