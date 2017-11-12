#include <iostream>

using namespace std;

typedef long long int lli;

/*
(A*B)%C = (A % C) * (B % C)
A^B%C = (A^(B/2)%C * A^(B/2)%C) % C, if B is even
A^B%C = (A * A^((B-1)/2)%C * A^((B-1)/2)%C) % C, if B is odd
*/

lli hmod(lli base, lli pow, lli mod){
    if(pow == 0)return 1;
    if(pow == 1)return base % mod;
    lli re = hmod(base, pow/2, mod);
    if(pow&1)return re * re * base % mod; // if pow is odd
    return re * re % mod;
}

int main(int argc, char** argv){
    lli base, pow, mod;
    while(cin >> base >> pow >> mod){
        cout << hmod(base, pow, mod) << '\n';
    }
    return 0;
}
