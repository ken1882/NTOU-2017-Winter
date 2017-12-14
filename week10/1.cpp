#include <cstdio>

void swap(int *a, int *b){
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void bubble_sort(int ar[], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(ar[j] > ar[j+1]){
                swap(&ar[j], &ar[j+1]);
            }
        }
    }
}

int main(){
    int n, a = 2, b = 3;

    while(~scanf("%d", &n)){
        int ar[1001] = {0};
        for(int i=0;i<n;i++){
            scanf("%d", &ar[i]);
        }
        bubble_sort(ar, n);
        for(int i=0;i<n;i++){
            printf("%d\n", ar[i]);
        }
    }
    return 0;
}
