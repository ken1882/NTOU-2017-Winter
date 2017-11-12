#include <cstdio>

int main(int argc, char* argv[]){
    auto a = 0, b = 0;
    while(~scanf("%d%d",&a, &b)){
        printf("sum:%d\n", a+b);
        printf("product:%d\n", a*b);
        printf("difference:%d\n", a-b);
        printf("quotient:%d\n", a/b);
        printf("remainder:%d\n", a%b);
    }
    return 0;
}
