#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char** argv){
    ios::sync_with_stdio(false);
    int a,b;
    while(cin >> a >> b){
        a += b;
        stringstream ss; ss << a;
        string str;
        ss >> str;
        int sum = 0;
        for(auto i:str){
            sum += i - '0';
        }
        cout << sum << endl;
    }
    return 0;
}
