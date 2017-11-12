#include <iostream>

using namespace std;

int main(int argc, char** argv){

    int n;
    while(~scanf("%d", &n)){
        int ascii_A = 65;
        for(int i=0, counter = 0;i<n;i++){
            for(int j=0, counter_2 = counter;j<n;j++){
                printf("%c", ascii_A + counter_2);
                counter_2 ^= 1;
            }
            printf("\n");
            counter ^= 1;
        }
    }

    return 0;
}
