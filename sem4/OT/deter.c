#include<stdio.h>
#include<math.h>

int determinant(int matrix[][10],int n){
    int det= 0;
    if(n==1){
        return matrix[0][0];
    }
    else if(n==2){
        return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];
    }
    else{
        int submatrix[10][10];
        int k,i,j;
        for(k=0; k<n; k++){
            int subi=0;
            for(i=1;i<n;i++){
                int subj=0;
                for(j=0; j<n; j++){
                    if(j!=k){
                        submatrix[subi][subj]= matrix[i][j];
                        subj++;
                    }
                }
                subi++;
            }
            det += pow(-1,k)*matrix[0][k]*determinant(submatrix, n-1);
        }
    }
    return det;
}
int main(){
    int n,i,j;
    printf("szie: ");
    scanf("%d", &n);
    int matrix[10][10];
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    int det = determinant(matrix, n);
    printf("determinant is: %d", det);
    return 0;
}