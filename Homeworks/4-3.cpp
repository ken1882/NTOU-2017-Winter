#include <iostream>

using namespace std;

int main(int argc, char** argv){
    int n;
    ios::sync_with_stdio(false);
    while(cin >> n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j == 0 || j == n - 1 || i == 0 || i == n - 1){
                    cout << 'A';
                }
                else{
                    cout << 'B';
                }
            }
            cout << '\n';
        }
    }
    return 0;
}
