#include <iostream>

using namespace std;

int main(int argc, char** argv){
    int n;
    while(cin >> n){
        int len = (n-1) * 2 + 1;
        for(int i=1;i <= n;i++){
            for(int j=0;j < len;j++){
                if(j >= len - (n - i))break;
                cout << (j < n - i ? ' ' : '*');
            }
            cout << '\n';
        }
    }
    return 0;
}

