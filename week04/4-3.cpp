#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char** argv){
    int n;
    while(cin >> n){
        int down = 3, mul = -1;
        double base = 4.0;
        printf("%.4f\n", base);
        for(int i=0;i<n-1;i++){
            base += (4.0 / down) * mul;
            mul *= -1; down += 2;
            printf("%.4f\n", base);
        }
    }
    return 0;
}
