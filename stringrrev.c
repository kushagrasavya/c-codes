#include <stdio.h>
#include <string.h>

int main(){
    int i, n, len;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    char arr[n], temp;
    printf("Enter String : ");
    scanf("%s",arr);
    len = strlen(arr)-1;
    for(i = 0; i < strlen(arr)/2; i++){
        temp = arr[i];
        arr[i] = arr[len];
        arr[len--] = temp;
    }
    printf("Reverse string :%s",arr);
    return 0;
}
// OR SECOND WAY!!
/*
#include<stdio.h>
#include<string.h>
int main(){
   char arr[5];
   printf("enter the string: ");
   scanf("%s", &arr);
  // strrev(arr);
  // printf("%s", arr);
   // for(int i=4; i>=0; i--){
    //    printf("%c", arr[i]);
    
    }
}
*/