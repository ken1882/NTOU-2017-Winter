#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef unsigned long long ull;

int main(int argc, char** argv){
    ios::sync_with_stdio(false);
    ull sum = 0;
    vector<int> table;
    table.push_back(0);
    for(int i=1;i<200;i++){
        ull n = 1;
        for(int j=0;j<i;j++){n *= i; n %= 10;}
        sum += n; sum %= 10;
        table.push_back(sum % 10);
    }
    for(int i=0;i<20;i++){
        if(i % 10 == 0)cout << "----------------------\n";
        for(int j=0;j<10;j++){
            cout << table[i * 10 + j] << ' ';
        }
        cout << endl;
    }
    string input;
    while(cin >> input){
        if(input == "0")break;
        int len = input.length();
        int n = input[len - 1] - '0';
        if(len > 1)n += (input[len - 2] - '0') * 10;
        cout << table[n] << endl;
    }
    return 0;
}
