#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(int argc, char** argv){
    ios::sync_with_stdio(false);
    int n;
    while(cin >> n){
        vector<int> ar, ar2;
        int cnta = 0, cntb = 0;
        for(int i=0, in;i<n;i++){
            cin >> in;
            ar.push_back(in);
        }
        for(int i=0, in;i<n;i++){
            cin >> in;
            ar2.push_back(in);
            if(in == ar[i])cnta++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i == j)continue;
                if(ar[i] == ar2[j])cntb++;
            }
        }
        cout << cnta << ' ' << cntb << '\n';
    }
    return 0;
}
