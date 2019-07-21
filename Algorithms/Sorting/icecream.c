#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int HASH[15000];

int find(int b[],int n,int a)
{
    for(int i=0;i<n;i++)
        if(b[i] == a)
        {
            if(HASH[i] == 0)
            {
                HASH[i] = 1;
                return i+1;
            }
        }

}
 
void swap(int a[],int j,int i)
{
    int temp;

    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int partition(int a[],int p,int r)
{
    int x = a[r];
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

void QuickSort(int a[],int p,int r)
{
    int q;
    if(p < r)
    {
        q = partition(a,p,r);
        QuickSort(a,p,q-1);
        QuickSort(a,q+1,r);
    }
}

void findIndex(int a[],int b[],int n,int m)
{
    int i=0,j=n-1,index1,index2;
    
    while(i<j)
    {
        if(a[i]+a[j] == m) 
        {
            index1 = find(b,n,a[i]);
            index2 = find(b,n,a[j]);
            if(index1>index2)
                printf("%d %d\n",index2,index1);
            else
                printf("%d %d\n",index1,index2);
            break;
        }
            if(a[i]+a[j] > m)
                j--;
            if(a[i]+a[j] < m)
                i++;       
    }
}

int main(){
    int t,b[10000]; 
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){
        int m; 
        scanf("%d",&m);
        int n; 
        scanf("%d",&n);
        int *a = malloc(sizeof(int) * n);
        for(int a_i = 0; a_i < n; a_i++){
           scanf("%d",&a[a_i]);
           b[a_i] = a[a_i];
       }
                    
          QuickSort(a,0,n-1);
            
          findIndex(a,b,n,m);
          for(int i=0;i<=10000;i++)
          HASH[i] = 0;
    }
    return 0;
}
