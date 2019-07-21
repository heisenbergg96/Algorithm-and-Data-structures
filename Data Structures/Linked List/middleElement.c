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

Node createLoop(Node H)
{
	Node head = H;
	while(head->data!=12)
		head = head->next;

	Node loop = head;
	while(head!=NULL) head = head->next;

	head = loop;
	return H;
}

Node detectLoop(Node Head)
{
	Node fast,slow;
	fast = Head->next->next;
	slow = Head->next;

	while(slow->data!=fast->data)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

Node middleElement(Node Head)
{
	Node fast,slow;

	fast = slow = Head;

	while(fast->next!=NULL && fast->next->next!=NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}

		return slow;
}



int main()
{
	Node Head = NULL;
	Node middle = NULL;

	Head = insert(Head,createNode(10));
	Head = insert(Head,createNode(11));
	Head = insert(Head,createNode(12));
	Head = insert(Head,createNode(13));
	Head = insert(Head,createNode(14));
	Head = insert(Head,createNode(15));
	Head = insert(Head,createNode(16));
	Head = insert(Head,createNode(17));
	Head = insert(Head,createNode(18));
	Head = insert(Head,createNode(19));
	Head = insert(Head,createNode(26));

	//print(Head);

	//middle = middleElement(Head);
	printf("\n");	
	//printf("%d \n",middle->data);
	
	
	Head = createLoop(Head);
	//Node loop = detectLoop(Head);
	print(Head);

	//printf("\nLoop detected at : %d",loop->data);

	return 0;
}