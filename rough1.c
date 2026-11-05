#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct student{
    char name[5][30];
    int enroll;
}std;
int main(){
    int x; std str;
    for(int i=0; i<5;i++){
        printf("enter name: ");
        scanf("%s", str.name[i][0]);
    }
}