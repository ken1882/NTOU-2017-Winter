#include <iostream>

using namespace std;

int main(int argc, char** argv){
    long long int base, pow;
    while(cin >> base >> pow){
        long long int sum = 1;
        for(long long int i=0;i<pow;i++){
            sum *= base;
        }
        cout << sum << '\n';
    }

    return 0;
}
