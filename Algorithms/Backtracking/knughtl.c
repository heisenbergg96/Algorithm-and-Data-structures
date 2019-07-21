#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
int flag;
int min(int a,int b){
    if(a>b)return a;
    return b;
}

int f1(int dist_x,int dist_y,int i,int j,int n){
    if(dist_x<0||dist_y<0 || dist_x>=n || dist_y >=n)return INT_MAX;
    int arr[8],min=INT_MAX;
    if(dist_x==0&&dist_y==0){flag=1;return 0;}
    else{
        arr[0]=1+f1(dist_x-i,dist_y-j,i,j,n);
        arr[1]=1+f1(dist_x-i,dist_y+j,i,j,n);
        arr[2]=1+f1(dist_x+i,dist_y-j,i,j,n);
        arr[3]=1+f1(dist_x+i,dist_y+j,i,j,n);
        
        arr[4]=1+f1(dist_x-j,dist_y-i,i,j,n);
        arr[5]=1+f1(dist_x-j,dist_y+i,i,j,n);
        arr[6]=1+f1(dist_x+j,dist_y-i,i,j,n);
        arr[7]=1+f1(dist_x+j,dist_y+i,i,j,n);
        for(int k=0;k<8;k++){
            if(min>arr[k])min=arr[k];
        }
        return min;

    }
}
int main(){
    int n; 
    scanf("%d",&n);
   // int a[n][n];
    int dist;
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            flag=0;
            dist = f1(n-1,n-1,i,j,n);
            if(flag)
            printf("%d ",dist);
            else printf("%d ",-1);
        }
        printf("\n");
    }
    return 0;
}

