#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char* argv[]){
    int a,b,c;
    while(~scanf("%d%d%d",&a, &b, &c)){
        printf("sum:%d\n", a+b+c);
        printf("average:%d\n", (a+b+c)/3);
        printf("smallest:%d\n", min(min(a,b),c));
        printf("largest:%d\n", max(max(a,b),c));
    }
    return 0;
}
