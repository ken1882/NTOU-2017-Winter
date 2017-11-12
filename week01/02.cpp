#include <stdio.h>

int main(int argc, char* argv[]){
    int age;
    printf("age:");
    scanf("%d", &age);
    if(age > 0)puts("Hello world!");

    return 0;
}
