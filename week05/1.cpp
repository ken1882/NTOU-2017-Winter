#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n;
    while(cin >> n){
        string spacing;
        cin >> spacing;
        for(int i = 0;i < n;i++){
            int ord = n - i - 1;
            for(int j=0;j < ord * 2; j++){
                cout << ' ';
            }
            int top = i + 1;
            for(int j= top;j > 0;j--){
                cout << j;
                if(j - 1 != 0)cout << spacing;
            }
            for(int j = 2; j <= top;j++){
                cout << spacing;
                cout << j;
            }
            cout << endl;
        }
    }
    return 0;
}
