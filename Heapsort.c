#include<stdio.h>
#include<stdlib.h>
void swap(int *x,int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
int heapify(int a[], int n){
    int p,i,c;
    for(i=n/2-1;i>=0;--i){
        p=i;
        while(p<n){
            c=2*p+1;
            if(c>=n){
                break;
            }
            else if(c<n-1 && a[c]<a[c+1]){
                c=c+1;
            }
            else if(a[p]<a[c]){
                swap(&a[p],&a[c]);
                p=c;
            }
            else{
                break;
            }
        }
    }
}
void heapsort(int a[], int n){
    
    heapify(a,n);
    for(int j=n-1;j>0;j--){
        swap(&a[0],&a[j]);
        heapify(a,j);
    }
     for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
}
int main()
{
    int arr[] = {78,32,12,18};
    int n = (sizeof(arr) / sizeof(arr[0]));
    heapsort(arr,n);
    return 0;

}
