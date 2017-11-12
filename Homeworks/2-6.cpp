#include <iostream>

using namespace std;

typedef unsigned long long int ull;

int main(){
    int n;
    cin >> n;
    while(n--){
        ull top, mod, sum = 0;
        cin >> top >> mod;
        if(top & 1){
            top = (top % mod) * ((top + 1) / 2 % mod);
        }
        else{
            top = (top / 2 % mod) * ((top + 1) % mod);
        }
        cout << top % mod << endl;
    }
    return 0;
}
