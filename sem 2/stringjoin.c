//concatenate two strings
#include<stdio.h>
int main(){
    int m,n,x;
    printf("enter the length of first string: ");
    scanf("%d", &n);
    printf("enter the length of second string: ");
    scanf("%d", &m);
    char a[n], b[m]; 
      x=m+n;
      char c[x];
    printf("enter the first string: ");
    scanf("%s", &a);
    printf("enter the second string: ");
    scanf("%s", &b);
    for(int i=0; i<n; i++){
        c[i]=a[i];
    }
    for(int i=n; i<x; i++){
        c[i]=b[i-n];
    }
    printf("the new string is :\n");
   for(int i=0; i<x; i++){
     printf("%c", c[i]);
   }
   return 0;
}

