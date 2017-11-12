#include <cstdio>

int main(int argc, char* argv[]){
    int n;
    printf("number of \"Hello world!\":");
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        puts("Hello world!");
    }
    return 0;
}
