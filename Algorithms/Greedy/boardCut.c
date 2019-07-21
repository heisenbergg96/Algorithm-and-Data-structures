#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void swap(long a[],long j,long i)
{
    long temp;

    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int partition(long a[],long p,long r)
{
    long x = a[r];
    long i = p-1;
    for(long j = p;j<r;j++)
        if(a[j] > x)
        {
            i++;
            swap(a,j,i);

        }
        
    swap(a,r,i+1);

    return i+1;
}

void QuickSort(long a[],long p,long r)
{
    long q;
    if(p < r)
    {
        q = partition(a,p,r);
        QuickSort(a,p,q-1);
        QuickSort(a,q+1,r);
    }
}

long cutBoard(long a[],long b[],long m,long n)
{
    long countx = 1,county = 1;
    long i=0,j=0,sum = 0;
    
    while(i<m-1 && j<n-1)
    {
        if(a[i] > b[j])
        {
            sum+=a[i]*countx;
            county++;
            i++;
        }
        else if(a[i] < b[j])
        {
            sum+=b[j]*county;
            countx++;
            j++;
        }
        else if(a[i] == b[j])
        {
            if(countx > county)
            {
                sum+=a[i]*countx;
                county++;
                i++;
            }
            else
            {
                sum+=b[j]*county;
                countx++;
                j++;
            }
        }
    }
    
    if(i == m-1)
    {
        while(j<n-1)
        sum+=b[j++]*county;
    }
    
    if(j == n-1)
    {
        while(i<m-1)
            sum+=a[i++]*countx;
    }
    
    return sum%(1000000007);
}

int main() {
    int q;
    long n,m,a[100000],b[100000];
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        scanf("%ld",&m);
        scanf("%ld",&n);
        for(long j=0;j<m-1;j++)
            scanf("%ld",&a[j]);
        for(long k=0;k<n-1;k++)
            scanf("%ld",&b[k]);
        QuickSort(a,0,m-2);
        QuickSort(b,0,n-2);
        
        printf("%ld\n",cutBoard(a,b,m,n));
    }
    return 0;
}
