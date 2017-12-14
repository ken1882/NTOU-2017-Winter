#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main(){
    string str;
    while(getline(cin, str)){
        int len = str.length();
        for(int i=0;i<len;i++){
            if(str[i] == ','){str[i] = '\n';}
        }
        stringstream ss(str);
        int n = 0; len = 0;

        vector<int> ar;
        while(ss >> n){
            ar.push_back(n);
            len++;
        }
        int maxlen = 1;
        vector< pair< int, vector<int> > > record;
        record.resize(len);
        for(int i=0;i<len;i++){
            for(int j=i+1, maxn, minn;j<len;j++){
                bool passed = true;
                maxn = max(ar[i], ar[j]);
                minn = min(ar[i], ar[j]);
                record[i].second.clear();
                record[i].second.push_back(ar[i]);

                for(int k=i+1;k<j;k++){
                    if(ar[k] < minn || ar[k] > maxn){
                        passed = false; break;
                    }
                    record[i].second.push_back(ar[k]);
                }
                record[i].second.push_back(ar[j]);
                if(passed){
                    record[i].first = j-i+1;
                    maxlen = max(j-i+1, maxlen);
                }
            }
        }
        #define Debug 0
        #if Debug
            for(auto p:record){
                cout << p.first << ": ";
                for(auto i:p.second)cout << i << ' ';
                cout << endl;
            }
        #endif
        cout << maxlen << '\n';
    }
    return 0;
}
