#include<stdio.h>
#include<math.h>

void cofactor(float [][25], float);
float determinant(float[][25], float);
void transpose(float [][25], float [][25], float);

int main(){
    float d,n;
    float a[25][25];
    int i,j;
    printf("size: ");
    scanf("%f", &n);
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            scanf("%f", &a[i][j]);
        }
    }
    d= determinant(a, n);
    printf("%d", d);
    if(d==0){
        printf("inverse is not possible!");
    }
    else{
        cofactor(a, n);
    }
}
 
float determinant(float a[25][25], float k){
    float s=1, det=0, b[25][25];
    int i,j,c,m,n;
    if(k==1){
        return a[0][0];
    }
    else{
        det = 0;
        for(c=0; c<k; c++){
            m=0;
            n=0;
            for(i=0;i<k;i++){
                for(j=0;j<k;j++){
                    b[i][j]=0;
                    if(i!=0 && j!=k){
                        b[m][n]=a[i][j];
                        if(n<(k-2)){
                            n++;
                        }
                        else{
                            n=0;
                            m++;
                        }
                    }
                }
            }
            det= det + s*(a[0][c]*determinant(b, k-1));
            s=-1*s;
        }
    }
    return det;
}

void cofactor(float num[25][25], float f){
    float b[25][25], fac[25][25];
    int p,q,i,j,m,n;
    for(q=0; q<f;q++){
        for(p=0;p<f;p++){
            m=0;
            n=0;
            for(i=0;i<f;i++){
                for(j=0;j<f;j++){
                    if(i!=q && j!=p){
                        b[i][j]= num[i][j];
                        if(n<(f-2)){
                            n++;
                        }
                        else{
                            n=0;
                            m++;
                        }
                    }
                }
            }
            fac[p][q]=pow(-1, p+q)*determinant(b,f-1);
        }
    }
    transpose(num, fac, f);
}

void transpose(float num[25][25], float fac[25][25], float r){
    float b[25][25], inverse[25][25],d;
    int i,j;
    for(i=0; i<r; i++){
        for(j=0;j<r;j++){
            b[i][j]=num[j][i];
        }
    }
    d= determinant(num, r);
    for(i=0; i<r; i++){
        for(j=0;j<r;j++){
            inverse[i][j]= b[i][j]/d;
        }
    }
    printf("the inverse is: \n");
       for(i=0; i<r; i++){
        for(j=0;j<r;j++){
        printf("%f", inverse[i][j]);
        }
    }
}