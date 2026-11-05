//equation solving

#include<stdio.h>

int main() {
    float A[3][3], inv[3][3], B[3][1], x[3][1], det = 0;
    
    printf("Enter elements of A matrix:\n");
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            scanf("%f", &A[i][j]);

    printf("Enter elements of B matrix:\n");
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 1; j++)
            scanf("%f", &B[i][j]);
    
    printf("The Question :\n");
    printf("%.2fX + %.2fY + %.2fZ = %.2f\n", A[0][0], A[0][1], A[0][2], B[0][0]);
    printf("%.2fX + %.2fY + %.2fZ = %.2f\n", A[1][0], A[1][1], A[1][2], B[1][0]);
    printf("%.2fX + %.2fY + %.2fZ = %.2f\n", A[2][0], A[2][1], A[2][2], B[2][0]);
    
    // Calculate determinant
    for (int i = 0; i < 3; i++)
        det = det + (A[0][i] * (A[1][(i + 1) % 3] * A[2][(i + 2) % 3] - A[1][(i + 2) % 3] * A[2][(i + 1) % 3]));

    if (det == 0) {
        printf("The determinant is zero. The system has no unique solution.\n");
        return 1; // Exiting with an error code
    }
    
    // Calculate inverse
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            inv[i][j] = ((A[(j + 1) % 3][(i + 1) % 3] * A[(j + 2) % 3][(i + 2) % 3]) -
                         (A[(j + 1) % 3][(i + 2) % 3] * A[(j + 2) % 3][(i + 1) % 3])) / det;

    // Calculate solution
    for (int i = 0; i < 3; i++) {
        x[i][0] = 0;
        for (int k = 0; k < 3; k++) {
            x[i][0] += inv[i][k] * B[k][0];
        }
    }
    
    // Print solution
    printf("\nSolution:\n");
    printf("X = %.2f\n", x[0][0]);
    printf("Y = %.2f\n", x[1][0]);
    printf("Z = %.2f\n", x[2][0]);    

    return 0;
}
