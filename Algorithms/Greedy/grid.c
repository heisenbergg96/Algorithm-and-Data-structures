#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void swap(char a[],int j,int i)
	{
		char temp;

		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}

	int partition(char a[],int p,int r)
	{
		char x = a[r];
		int i = p-1;
		for(int j = p;j<r;j++)
			if(a[j] < x)
			{
				i++;
				swap(a,j,i);

			}
			
		swap(a,r,i+1);

		return i+1;
	}

	void QuickSort(char a[],int p,int r)
	{
		int q;
		if(p < r)
		{
			q = partition(a,p,r);
			QuickSort(a,p,q-1);
			QuickSort(a,q+1,r);
		}
	}

char *isSorted(char b[],int n)
{
    for(int i=0;i<n-1;i++)
        if(b[i+1]<b[i]) return "NO";
    return "YES";
}

int main() {

    int t,n,p=0,q;
    char a[110],b[15000];
    
    scanf("%d",&t);
    scanf("%d",&n);
    
    for(int x=0;x<t;x++)
    {
        for(int j=0;j<n;j++)
        {
            for(int i=0;i<n;i++)
                scanf("%c",&a[i]);
            QuickSort(a,0,n-1);
            for(int k=0;k<n;k++)
                b[p++] = a[k];
        }
        for(int j=0;j<p;j++)
        	printf("%2c ",b[j]);
    printf("%s\n",isSorted(b,p));
    }
    return 0;
}
