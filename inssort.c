#include<stdio.h>
#include<stdlib.h>
typedef struct test{
    int* arr;
}test;
void init(test *st, int size){
    st->arr=(int*)malloc(size*sizeof(int)); 
}
int arrayadd(test *st, int n){
    int i;
    for(int i=0; i<n; i++){
       scanf("%d", &st->arr[i]);
    }
}
int print(test *st, int n){
    for(int i=0; i<n;i++){
        printf("%d", st->arr[i]);
    }
}
void sort(test *st, int size){
    int j, i,temp;
    for(i=1;i<size;i++){
         temp=st->arr[i];
        j=i-1;
        while(j>=0 && st->arr[j]>temp){
           st->arr[j+1]=st->arr[j];
           j--;
        }
        st->arr[j+1]=temp;
    }
}
int main(){
    test arr;  int n;
    printf("enter the size of arr: ");
    scanf("%d", &n);
      init(&arr,n);
      arrayadd(&arr, n);
     
      sort(&arr, n);
      print(&arr,n);
}
