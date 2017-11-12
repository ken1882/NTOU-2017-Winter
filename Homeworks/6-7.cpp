#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

string int_to_str(int n){
    stack<int> digits;
    string re = "";
    while(n){
        digits.push(n%10);
        n /= 10;
    }
    while(!digits.empty()){
        n = digits.top(); digits.pop();
        re += (char)((n % 10) + 48);
    }
    return re;
}

pii similarity(string a, string b){
    int lena = a.length(), lenb = b.length(), ca = 0, cb = 0;
    for(int i=0;i<lena;i++){
        for(int j=0;j<lenb;j++){
            if(i == j){
                if(a[i] == b[j])ca++;
                continue;
            }
            if(a[i] == b[j])cb++;
        }
    }
    pii re(ca, cb);
    return re;
}

bool valid(string str){
    int len = str.length();
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            if(i != j && str[i] == str[j])return false;
        }
    }
    return true;
}

int main(int argc, char** argv){
    ios::sync_with_stdio(false);
    int cas;
    cin >> cas;
    while(cas--){
        int n, k;
        cin >> n;
        vector<string> conditions;
        vector<pii> diffs;
        string in;
        for(int i=0, a, b;i<n;i++){
            cin >> in >> a >> b;
            conditions.push_back(in);
            pii resp(a,b);
            diffs.push_back(resp);
        }
        int cnt = 0;
        for(int i=1000;i<10000;i++){
            string str = int_to_str(i);
            if(!valid(str))continue;
            bool passed = true;
            for(int j=0;j<n;j++){
                if(similarity(conditions[j], str) != diffs[j]){
                    passed = false; break;
                }
            }
            if(passed){
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}
