#include<stdio.h> 
void main(){
//create and write a file 
FILE *fptr; 
char name[20]; 
int age; 
    fptr = fopen("demo.txt", "w");
    printf("enter the name\n"); 
    scanf("%s",name); 
    fprintf(fptr,"Name: %s ",name);
    printf("enter the age\n"); 
    scanf("%d", &age); 
    fprintf(fptr,"Age: %d",age);
    fclose(fptr);
//reading a file 
        FILE *ptr; 
        char ch; 
        ptr = fopen("demo.txt", "r");
    if(ptr==NULL){
        printf("file cant open");
    }
        printf("after reading file content\n"); 
    while(!feof(ptr)){ 
    ch = fgetc(ptr); 
    printf("%c",ch); 
    }
    fclose(ptr);
}

