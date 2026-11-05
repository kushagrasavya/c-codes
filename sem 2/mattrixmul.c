#include <stdio.h>

int main() {
    int m, n;
    printf("Enter order of first matrix, m: ");
    scanf("%d",&m);
    printf("Enter order of second matrix, n: ");
    scanf("%d",&n);
    int a[m][n], b[m][n], res[m][n];
    if (m != n) {
        printf("Matrix of different size cannot be multipied\n");
    }
    printf("Enter the value of first matrix: \n");
    for (int i = 0; i< m; i++) {
        for (int j = 0; j< n; j++){
            printf("Enter element a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the value of second matrix: \n");
    for (int i = 0; i< m; i++) {
        for (int j = 0; j< n; j++){
            printf("Enter element b[%d][%d]: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }
    printf("Multiplication of the matrix: \n");
    for (int i = 0; i<m; i++) {
        for (int j = 0; j<n; j++) {
            res[i][j]=0;
            for (int x = 0; x<n; x++) {
                res[i][j] += a[i][x] * b[x][j];
            }
        }
    }
    printf("The product of the two matrices is: \n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d  ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}