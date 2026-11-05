#include <stdio.h>  
#include <stdlib.h>
void swap(int *p,int *q)
{
    int temp=*p;
    *p=*q;
    *q=temp;
}
void quickSort(int a[],int beg,int end)
{
    int down=beg,up=end,temp,p;
    p=beg+(rand()%((end-beg)));           // p=beg+(rand()%((end-beg)+1)); 
    swap(&a[p],&a[beg]); //
    p=a[beg];
    while(down<up)
    {
        while(p<a[up]&&up>beg)
        {
            up--;
        }
        while(p>=a[down]&&down<end)
        {
            down++;
        }
        if(down<up)
        {
            swap(&a[up],&a[down]);
        }
    }
    a[beg]=a[up];
    a[up]=p;
    if((up-beg)>1)
        quickSort(a,beg,up-1);
    if((end-up)>1)
        quickSort(a,beg,end);
}
int main()
{
    int a[]={13,12,9,10,9,0,-7,99,66};
    int end=sizeof(a)/sizeof(a[0]);
    quickSort(a,0,end);
    for(int i=0;i<end;i++)
    printf(" %d",a[i]);
    return 0;
}