#include<stdio.h>

/* input an mxn matrix */
void input(const float M[],int* m,int* n);

/* calculate the sum of two mxn matrices by the formula */
/* C_{ij} = A_{ij}+B_{ij} */

int get_index(const float Mat[], int height, int x, int y){
    return Mat[y * height + x];
}

void input(const float M[],int* m,int *n){
    int height, width;
    scanf("%d%d", &height, &width);
    *m = height; *n = width;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            scanf("%f", &M[i * height + j]);
        }
    }
}

void add(const float A[], const float B[], float C[],int m,int n){
    int height = m, width = n;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            int index = i * height + j;
            C[index] = A[index] + B[index];
        }
    }
}

void output(const float M[],int m,int n);

int main(){
   float A[100],B[100],C[100];
   int   m1,n1, m2, n2 ,c, i;

   scanf("%d",&c);
   for (i = 0; i < c; ++i) {
       input(A,&m1,&n1);
       input(B,&m2,&n2);

      if (m1 != m2 || n1 != n2) {
          printf("cannot add two incompatible matrices\n");
       } else {
          add(A,B,C,m1,n1);
          output(C,m1,n1);
       }
   }
   return 0;
}

void output(const float M[],int m,int n)
{
    int u = 0;
    const float* p = M, *ep = M+m*n;
    for(; p != ep; ++p) {
        printf((++u % n == 0) ? "%4.2f\n" : "%4.2f,", *p);
    }
    return;
}
/*
1
3 3
1 2 3
4 5 6
7 8 9
3 3
7 8 9
4 3 2
1 2 3
*/
