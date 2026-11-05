#include <stdio.h>  
void MatrixChainMult(int arr[],int n)         // length starts from 0
{
    int x=n-1;
    int minMul[x][x],s[x][x];
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<x;j++)
        {
            minMul[i][j]=0;
            s[i][j]=0;
        }
    }
    int j,q;
    for(int i=0;i<x;i++)
    minMul[i][i]=0; 
for(int L=1;L<x;L++)
{
    for(int i=0;i<x-L;i++)
    {
        j=i+L;
        minMul[i][j]=999999;
        for(int k=i;k<=j-1;k++)
        {
            q=minMul[i][k]+minMul[k+1][j]+arr[i]*arr[k+1]*arr[j+1];
            if(q<minMul[i][j])
            {
            minMul[i][j]=q;
            s[i][j]=k+1;         // k+1;
            }

        }
    }
}
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<x;j++)
        {
            printf("\t%d ",minMul[i][j]);
        }
        printf("\n");
    }
    printf("-----------------------------\n");
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<x;j++)
        {
            printf("\t%d ",s[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int arr[]={2,3,4,5,2,6};
    int size=sizeof(arr)/sizeof(arr[0]);
    MatrixChainMult(arr,size);
    return 0;

}