#include <iostream>

using namespace std;

int main(int argc, char** argv){
    int n;
    ios::sync_with_stdio(false);
    while(cin >> n){
        if((n%4 == 0 && n%100 != 0) || n%400 == 0){
            cout << "leap\n";
        }
        else{
            cout << "nonleap\n";
        }
    }
    return 0;
}
