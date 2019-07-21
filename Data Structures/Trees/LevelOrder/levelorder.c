#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct node 
{
	int data;
	struct node *left;
	struct node *right;
}*Node;


typedef struct queue
{
	int r,f;
	Node a[100];
}Queue;

Queue create()
{
	Queue q;
	
	for(int i=0;i<100;i++)
		q.a[i] = NULL;
		
	q.r = -1;
	q.f = 0;
	
	return q;
}

void Enqueue(Node temp,Queue *q)
{
	q->a[++q->r] = temp;	
}

void Dequeue(Queue *q)
{
	q->a[q->f++];
}

Node getFront(Queue *q)
{
	return q->a[q->f];	
}

int isempty(Queue q)
{
	return q.f > q.r;
}

int hasBothChild(Node k)
{
	if(k->left!=NULL && k->right!=NULL)
		return 1;
	else
		return 0;
}

Node getNode(int data)
{
	Node nnode = NULL;
	nnode = (Node)malloc(sizeof(struct node));
	nnode->data = data;
	nnode->right = nnode->left = NULL;
	
	return nnode;
}


Node insert(Node temp,Node root,Queue *q)
{
	
    if (!root)
    {
        root = temp;
        Enqueue(temp,q);

        return root;
    }
        
 
    else
    {
        Node front = getFront(q);

        if (!front->left)
        {
            front->left = temp;
        }

        else if (!front->right)
        {
            front->right = temp;
        }
 
        if (hasBothChild(front))
            Dequeue(q);
    }

    Enqueue(temp,q);
    
    return root;
}

void printLevel(Node root)
{
	Queue q = create();
	Enqueue(root,&q);
	Enqueue(NULL,&q);
	
	int current_sum = 0;
	
	while(!isempty(q))
	{
		Node temp = getFront(&q);
		Dequeue(&q);
		
		if(!temp)
		{
			printf("%d \n",current_sum);
			current_sum = 0;
			Enqueue(NULL,&q);
		}
		else
		{
			current_sum+=temp->data;
			
			if(temp->left)
				Enqueue(temp->left,&q);
			if(temp->right)
				Enqueue(temp->right,&q);
		}
	}
}

void levelOrderPrint(Node root)
{
	Queue q = create();
	Enqueue(root,&q);
	
	while(!isempty(q))
	{
		Node temp = getFront(&q);
		Dequeue(&q);
		printf("%d ",temp->data);
		
		if(temp->left)
			Enqueue(temp->left,&q);
		if(temp->right)
			Enqueue(temp->right,&q);
	}
}

void print(int a[],int n)
{
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
		
	printf("\n");
}

void printPath(Node root,int path[],int pathlen)
{
	if(!root)
		return;
	
	path[pathlen] = root->data;
	pathlen++;
	
	if(!root->left && !root->right)
		print(path,pathlen);
	else
	{
		printPath(root->left,path,pathlen);
		printPath(root->right,path,pathlen);
	}
}



void preorderDotDump (Node root, FILE* outputFile)
{
	if (root != NULL) 
	{
		fprintf (outputFile, "%d [label=%d,color=black];\n",root->data, root->data);
		
		if (root->left != NULL) 
		         fprintf (outputFile, "%d -> %d ;\n", root->data, (root->left)->data);
		
        	if (root->right != NULL)
            	   fprintf (outputFile, "%d -> %d;\n", root->data, root->right->data);
            		
        	preorderDotDump (root->right, outputFile);
        	preorderDotDump (root->left, outputFile);
    	}
}

void dotDump(Node root, FILE *outFile)
{

	fprintf (outFile, "digraph Heap {\n");
	
	preorderDotDump (root, outFile);
    	fprintf (outFile, "}\n");
}


FILE *outputFile;

void main(int argc,char *argv[])
{
	int num,i;
	FILE *pipe;
	Node root = NULL;
	Queue q;
	
	if(argc!=2)
	{
		printf("2 arguments in command line!!!!");
		exit(0);
	}

	num = atoi(argv[1]);
	q = create();
	
	outputFile = fopen ("heap.dot", "w");
	fclose (outputFile);
	
	srand(time(NULL)); 

	for(i=0;i<num;i++)
	{ 
		Node nnode = getNode(rand()%1000);
		root = insert(nnode,root,&q);
	}
	
		//levelOrderPrint(root);
		printLevel(root);
		//int a[100];
		//printPath(root,a,0);
	
	outputFile = fopen ("heap.dot", "a");
        if(outputFile != NULL) 
              dotDump (root,outputFile);
    fclose(outputFile);	
	
	pipe=popen("dot -Tps heap.dot -o heap.ps","w");
	pclose(pipe);	
	pipe=popen("evince heap.ps","r"); 
	pclose(pipe);
	

}












