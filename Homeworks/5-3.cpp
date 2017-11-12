#include <iostream>

using namespace std;

typedef unsigned long long int ull;

const string spacing = "  ";

ull cnt = 0;

ull f(ull n, ull level){
    for(int i=0;i<level;i++)cout << spacing;
    cout << "#call:" << ++cnt << ",fibonacci(" << n << ")\n";
    if(n <= 1)return n;
    return f(n-1, level+1) + f(n-2, level+1);
}

int main(int argc, char** argv){
    ull n;
    while(cin >> n){
        cnt = 0;
        f(n, 0);
    }
    return 0;
}
