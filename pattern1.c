//program to print FC pattern
#include<stdio.h>
int main(){
for(int i=1; i<=7; i++){
    if(i==1){
        for(int j=1; j<=6; j++){
            printf("#");
        }
    }
    else if(i==3){
        for(int j=1; j<=5; j++){
            printf("#");
        }

    }
    else{
        printf("#");

    }
    printf("\n");
}
printf("\n\n");
for(int i=1; i<=9; i++){
    if(i==1 || i==9){
        for(int j=1; j<=3; j++){
            printf(" ");
        }
        for(int j=4; j<=9; j++){
            printf("#");
        }
    }
    else if(i==2 || i==8){
       printf(" ");
       for(int j=2; j<=11; j++){
       if(j==2 || j==3 || j==10 || j== 11){
        printf("#");
       }
       else {
        printf(" ");
       }
    
    }
    }
    else{
        printf("#");
    }
    printf("\n");
}
}


    
