#include<stdio.h>

void swap(int x,int y){
    int temp;
    temp=*x;
    x=y;
    *y=temp;
}

void isort(int array[],int n){
    int i,j;
    for(i=0;i<n;i++){
        int c=array[i];
        j=i-1;
        while(j>=0 && c<array[j]){
            array[j+1]=array[j];
            j--;
        } 
        array[j+1]=c;
    }

    for(i=0;i<n;i++){
        printf("%d\t",array[i]);
    }
}

int main(){
    int n; 
    printf("enter lenght of array:\n");
    scanf("%d",&n);
    int array[n];
    int i,j,key;

    for(i=0;i<n;i++){
        printf("enter element[%d]:",i+1);
        scanf("%d",&array[i]);
    }
    isort(array,n);
    return 0;
}