#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
	int height;
}*Node;

Node GetNode(int data)
{
	Node nnode = (Node)malloc(sizeof(struct node));
	nnode->data = data;
	nnode->right = NULL;
	nnode->right = NULL;
	nnode->height = 0;

	return nnode;
}


Node insert(Node root,Node nnode)
{
	if(root == NULL)
		return nnode;

	if(root->data > nnode->data)
		root->left = insert(root->left,nnode);
	else 	
	if(root->data < nnode->data)	 	
		root->right = insert(root->right,nnode);
	
	return root;
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

	fprintf (outFile, "digraph BST {\n");
	
	preorderDotDump (root, outFile);
    	fprintf (outFile, "}\n");
}


FILE *outputFile;

Node swapTree(Node root)
{
	Node temp = NULL;
	
	if(root == NULL)
		return NULL;
		
	temp = swapTree(root->left);
	root->left = swapTree(root->right);
	root->right = temp;
	
	return root;
}

void main(int argc,char *argv[])
{
	int n,i,key;
	FILE *pipe;

	if(argc!=2)
	{
		printf("2 arguments in command line!!!!");
		exit(0);
	}
	outputFile = fopen ("bs.dot", "w");
	fclose (outputFile);
	n = atoi(argv[1]);
	Node root = NULL;
	srand(time(NULL));

	for(i=0;i<n;i++)
	{
		Node nnode = GetNode(rand()%100);
		root = insert(root,nnode);
		
		outputFile = fopen ("bs.dot", "a");
		if(outputFile != NULL) 
			dotDump (root,outputFile);			
		fclose(outputFile);
	}

	
	
		
	root = swapTree(root);
	
	outputFile = fopen ("as.dot", "a");
		if(outputFile != NULL) 
			dotDump (root,outputFile);			
		fclose(outputFile);
	
	pipe=popen("dot -Tps bs.dot -o bs.ps","w");
	pclose(pipe);	
	pipe=popen("evince bs.ps","r"); 
	pclose(pipe);
	
	
	pipe=popen("dot -Tps as.dot -o as.ps","w");
	pclose(pipe);	
	pipe=popen("evince as.ps","r"); 
	pclose(pipe);
}
