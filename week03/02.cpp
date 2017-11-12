#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
    int n;
    cin >> n;
    while(n--){
        int a,b,sum = 0;
        cin >> a >> b;
        for(int i=a;i<=b;i++){
            if(!(i&1))continue;
            sum += i;
        }
        cout << sum << '\n';
    }
    return 0;
}
