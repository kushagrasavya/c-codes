#include<stdio.h>
int bbsort(int* str, int n){
     int temp=0; int flag;
    for(int i=0; i<n-1; i++){
        int flag=0;
        for(int j=0; j<n-1-i; j++){
            if((str[j])>(str[j+1])){
                temp=(str[j]);
                (str[j])=(str[j+1]);
                (str[j+1])=temp;
                 flag=1;
            }
        }
         if(flag=0){
            break;
        }
       }
      for(int i=0; i<n; i++){
     printf("%d", str[i]);
   } 
}
int main(){
    int n;
    printf("enter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("enter the array: ");
    for(int i=0; i<n;i++){
        scanf("%d", &arr[i]);
    }
   bbsort(arr, n);
   //for(int i=0; i<n; i++){
     //printf("%d", p[i]);
   //}
}