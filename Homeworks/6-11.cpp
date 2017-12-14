#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    int cas;
    cin >> cas;
    while(cas--){
        int n;
        cin >> n;
        vector<int> ar, ar_sorted;
        map<int, int> loc;
        for(int i=0, in;i<n;i++){
            cin >> in;
            ar.push_back(in);
            loc[in] = i;
        }
        ar_sorted = ar;
        sort(ar_sorted.begin(), ar_sorted.end());
        for(int i=0;i<n-1;i++){
            cout << loc[ ar_sorted[i] ] << ' ';
        }
        cout << loc[ar_sorted[n-1]] << '\n';
    }
    return 0;
}
/*
2
5
2 7 3 4 1
3
5 4 6
*/
