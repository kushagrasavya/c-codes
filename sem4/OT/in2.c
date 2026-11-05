#include<stdio.h>
#include<math.h>

float cofactor(float [][25], int);
float determinant(float[][25], int);
void transpose(float [][25], float [][25], int);

int main() {
    int n;
    printf("Size: ");
    scanf("%d", &n);
    float a[25][25];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%f", &a[i][j]); // corrected input format specifier
        }
    }
    float det = determinant(a, n);
    printf("Determinant: %.2f\n", det); // corrected output format specifier
    if(det == 0) {
        printf("Inverse is not possible!\n");
    } else {
        cofactor(a, n);
    }
    return 0;
}

float determinant(float a[25][25], int k) {
    float s=1, det=0, b[25][25];
    if(k==1){
        return a[0][0];
    } else {
        det = 0;
        for(int c=0; c<k; c++){
            int m=0, n=0;
            for(int i=0; i<k; i++){
                for(int j=0; j<k; j++){
                    b[i][j]=0;
                    if(i!=0 && j!=c){
                        b[m][n]=a[i][j];
                        if(n<(k-2)){
                            n++;
                        } else{
                            n=0;
                            m++;
                        }
                    }
                }
            }
            det += s * (a[0][c] * determinant(b, k-1));
            s = -1 * s;
        }
    }
    return det;
}

float cofactor(float num[25][25], int f) {
    float b[25][25], fac[25][25];
    for(int q=0; q<f; q++){
        for(int p=0; p<f; p++){
            int m=0, n=0;
            for(int i=0; i<f; i++){
                for(int j=0; j<f; j++){
                    if(i!=q && j!=p){
                        b[m][n]= num[i][j];
                        if(n<(f-2)){
                            n++;
                        } else{
                            n=0;
                            m++;
                        }
                    }
                }
            }
            fac[p][q]=pow(-1, p+q)*determinant(b, f-1);
        }
    }
    transpose(num, fac, f);
}

void transpose(float num[25][25], float fac[25][25], int r) {
    float b[25][25], inverse[25][25], d;
    for(int i=0; i<r; i++){
        for(int j=0; j<r; j++){
            b[i][j]=num[j][i];
        }
    }
    d= determinant(num, r);
    for(int i=0; i<r; i++){
        for(int j=0; j<r; j++){
            inverse[i][j]= b[i][j]/d;
        }
    }
    printf("The inverse is: \n");
    for(int i=0; i<r; i++){
        for(int j=0; j<r; j++){
            printf("%.2f ", inverse[i][j]); // corrected output format specifier
        }
        printf("\n");
    }
}
