//programe to add individual rows and coloumns of a mattrix
#include<stdio.h>
int main(){
    int sumr=0; int sumc=0;
    int a[3][3]; int j,k;
    printf("enter the array: ");
    for(int i=0; i<3; i++){
        for( k=0; k<3; k++){
            scanf("%d", &a[i][k]);
        }

    }
    for(int i=0; i<3; i++){
        sumr = 0;
        for(int j=0;j<3; j++){
             
            sumr+=a[i][j];

        }
        printf("sum of %d row is %d\n", i, sumr);
    }
    for(int i=0; i<3; i++){
        sumc = 0;
        for( j=0; j<3; j++){
            sumc+=a[j][i];
           
        }
         printf("sum of %d coloumn is %d\n", i, sumc );
    }
    return 0;
}