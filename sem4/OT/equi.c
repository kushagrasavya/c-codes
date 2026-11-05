#include<stdio.h>
#include<math.h>
int main(){
    float a[3][3], inv[3][3], b[3][1],x[3][1], det=0;


        printf("Enter elements of A matrix:\n");
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            scanf("%f", &a[i][j]);

    printf("Enter elements of B matrix:\n");
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 1; j++)
            scanf("%f", &b[i][j]);
    
    printf("The Question :\n");
    printf("%.2fX + %.2fY + %.2fZ = %.2f\n", a[0][0], a[0][1], a[0][2], b[0][0]);
    printf("%.2fX + %.2fY + %.2fZ = %.2f\n", a[1][0], a[1][1], a[1][2], b[1][0]);
    printf("%.2fX + %.2fY + %.2fZ = %.2f\n", a[2][0], a[2][1], a[2][2], b[2][0]);

    for(int i=0; i<3; i++){
        det = det + (a[0][i] * (a[1][(i+1)%3]*a[2][(i+2)%3] - a[1][(i+2)%3] * a[2][i+1%3]));
    }
     if (det == 0) {
        printf("The determinant is zero. The system has no unique solution.\n");
        return 1; // Exiting with an error code
    }

    for(int i=0; i<3;i++){
        for(int j=0; j<3; j++){
            inv[i][j]= ((a[(j+1)%3][(i+1%3)]*a[(j+2)%3][(i+2)%3])-(a[(j+1)%3][(i+2)%3]*a[(j+2)%3][(i+1)%3]))/det;
        }
    }
    for(int i=0; i<3; i++){
        x[i][0]=0;
        for(int k=0; k<3;k++){
            x[i][0]= inv[i][k]*b[k][0];
        }
    }

      printf("\nSolution:\n");
    printf("X = %.2f\n", x[0][0]);
    printf("Y = %.2f\n", x[1][0]);
    printf("Z = %.2f\n", x[2][0]);    

    return 0;
}