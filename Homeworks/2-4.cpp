#include <iostream>

using namespace std;

typedef unsigned long long int ull;

int main(){
    ull table[13] = {};
    for(int sum = 1, i = 1; i < 13; i++){
        table[i] = (sum *= i);
    }
    int n;
    cin >> n;
    while(n--){
        int in;
        cin >> in;
        cout << table[in] << '\n';
    }
    return 0;
}
