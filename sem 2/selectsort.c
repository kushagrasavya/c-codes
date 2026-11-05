#include<stdio.h>
#include<stdlib.h>
int arrcreate(int* arr, int n){
    printf("enter the array: ");
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
}
int swap(int* a, int* b){
    int c=0;
    c=*a;
    *a=*b;
    *b=c;  
}
int print(int* arr, int n){
     for(int i=0;i<n;i++){
        printf("%d\n", arr[i]);
    }
}
int sort(int* st, int n){
    int a,j;
    for(int i=0; i<n-1;i++){
        a=i;
        for(j=i+1;j<n;j++){
        if(st[j]<st[a]){
            a=j;
        }
      }  
       if(a!=i){
        swap(&st[i],&st[a]);    
        }
    }
}
int main(){
    int n;
    printf("enter the size of arrray: ");
    scanf("%d", &n);
    int arr[n];
    arrcreate(arr, n);
    sort(arr, n);
    print(arr, n);
}