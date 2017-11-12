#include <iostream>

using namespace std;

typedef unsigned long long int ull;

int main(){
    int n;
    cin >> n;
    while(n--){
        ull top, mod, sum = 0;
        cin >> top >> mod;
        cout << (((1 + top) * top / 2) % mod) << '\n';
    }
    return 0;
}
