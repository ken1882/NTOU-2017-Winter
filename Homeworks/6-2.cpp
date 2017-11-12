#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

int main(){
    ull a,b;
    ios::sync_with_stdio(false);
    while(cin >> a >> b){
        if(a + b == 0)break;
        vector<ull> numa, numb;
        if(b > a)swap(a,b);
        while(a){
            numa.push_back(a%10);
            a /= 10;
        }
        numa.push_back(0);
        int dig = 0, cnt = 0;
        while(b){
            numa[dig++] += b % 10;
            b /= 10;
        }
        dig = numa.size();
        for(int i=0;i<dig;i++){
            if(numa[i] >= 10){
                numa[i + 1]++;
                cnt++;
            }
        }
        if(cnt == 0){
            cout << "No carry operation.";
        }
        else if (cnt == 1){
            cout << "1 carry operation.";
        }
        else{
            cout << cnt << " carry operations.";
        }
        cout << '\n';
    }
    return 0;
}
