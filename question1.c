#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student{
    char name[30];
    int enroll;
}std;
int main(){
    int n; int y; int flag; std temp;
      printf("enter the number of data to be inputed: ");
      scanf("%d", &y);
      printf("\n");
      std id[y];
      for(int i=0; i<y; i++){
        printf("enter name of %d student: ", i);
        scanf("%s", &id[i].name);
        printf("\n");
        printf("enter enrollment number of %d student: ",i);
        scanf("%d", &id[i].enroll);
        printf("\n");
      }
      
      //sorting used- Advanced bubble sort
      for(int i=0; i<y-1; i++){
        flag=0;
        for(int k=0; k<y-1-i;k++){
            if(id[k].enroll> id[k+1].enroll){
                 temp=id[k];
                 id[k]=id[k+1];
                 id[k+1]=temp;
                 flag=1;
            }
        }
        if(flag==0){
            break;
        }
      }
    for(int i=0; i<y;i++){
        printf("%d student name is: %s and enroll number is: %d\n",i, id[i].name, id[i].enroll);
 
    }
}