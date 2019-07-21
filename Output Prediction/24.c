#include<stdio.h>

int main()
{
	int i;
	int it[10];
	float f;
	double d;
	char c;
	char ch[10];
	//void q;
	void *p;
	int *ptr;
	float *fptr;

	printf("integer = %ld\nfloat = %ld\ndouble = %ld\ncharacter = %ld\n",sizeof(i),sizeof(f),sizeof(d),sizeof(c));
	printf("pointer to integer = %ld\npointer to float = %ld\n",sizeof(ptr),sizeof(fptr));

}
