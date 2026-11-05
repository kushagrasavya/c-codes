#include <stdio.h>
void countingSort(int A[],int B[],int k,int n)
{   int c[k+1];             //since element can start from 0 upto n-1 i.e. [0,n)
    for(int i=0;i<=k;i++)
        c[i]=0;
    for(int j=0;j<n;j++)
        c[A[j]]=c[A[j]]+1;
    for(int i=1;i<=k;i++)
        c[i]=c[i]+c[i-1];
    for(int j=n-1;j>=0;j--)
    {
        B[c[A[j]]-1]=A[j];
        c[A[j]]=c[A[j]]-1;
    }
}
int main()
{
    int A[]={0,0,1,7,5,2,3,4};
    int n,k=A[0];
    n=sizeof(A)/sizeof(A[0]);
    int B[n];
    for(int i=1;i<n;i++)
        k=(k>=A[i])?k:A[i];
    // printf("k=%d",k);
    countingSort(A,B,k,n);
    for(int i=0;i<n;i++)
        printf(" %d",B[i]);
    return 0;
}