#include <iostream>
#include <cstring>
#include <map>

using namespace std;

typedef unsigned long long ull;

int main(int argc, char** argv){
    ull n, maxn, minn;
    ios::sync_with_stdio(false);
    while(cin >> n >> minn >> maxn){
        map<ull, ull>counter;

        for(ull i=0, in;i<n;i++){
            cin >> in;
            counter[in]++;
        }
        for(auto i:counter){
            cout << i.first << " appears ";
            if(i.second == 1){
                cout << "1 time";
            }
            else{
                cout << i.second << " times";
            }
            cout << '\n';
        }
    }
    return 0;
}
