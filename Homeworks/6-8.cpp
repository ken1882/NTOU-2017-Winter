#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;
typedef unsigned long long ull;

vector< vector<int> > conditions;
vector<pii> compares;

//------------------------------------------------
pii calc_new_sim(int n, int pos, vector<int> cmp);
//------------------------------------------------
int conds, depth;
int table[] = {0,1,2,3,4,5,6,7,8,9};
bool used[10];
//------------------------------------------------
void enum_numbers(int ar[], int cur_depth, vector<pii> cmp_results, int &out){
    for(int i=0;i<10;i++){
        if(cur_depth == 0 && table[i] == 0)continue;
        if(used[i])continue;

        bool processed = true;
        vector<pii> temp_result = cmp_results;

        for(int j=0;j<conds;j++){
            pii add = calc_new_sim(table[i], cur_depth, conditions[j]);
            temp_result[j].first  = cmp_results[j].first  + add.first;
            temp_result[j].second = cmp_results[j].second + add.second;

            if(temp_result[j].first > compares[j].first){
                processed = false; break;
            }
            else if(temp_result[j].second > compares[j].second){
                processed = false; break;
            }

            if(cur_depth == depth - 1){
                if(temp_result[j].first != compares[j].first){
                    processed = false; break;
                }
                if(temp_result[j].second != compares[j].second){
                    processed = false; break;
                }
            }
        }
        if(!processed)continue;
        if(cur_depth == depth - 1){
            /*
            cout << "---------------------------\n";
            for(int j=0;j<depth-1;j++)cout << ar[j];
            cout << table[i] << '\n';
            cout << temp_result[0].first << ' ' << temp_result[0].second << '\n';
            pii add = calc_new_sim(table[i], cur_depth, conditions[0]);
            cout << "Number: " << table[i] << " at " << cur_depth << '\n';
            cout << add.first << ' ' << add.second << '\n';
            */
            out++;
            continue;
        }
        int next_depth = cur_depth + 1;
        used[i] = true;
        ar[cur_depth] = table[i];
        enum_numbers(ar, next_depth, temp_result, out);
        used[i] = false;
        for(int j = next_depth; j < depth;j++){
            ar[j] = -2;
        }
    }
}
//------------------------------------------------
int main(){
    ios::sync_with_stdio(false);
    int cas;
    cin >> cas;
    while(cas--){
        cin >> conds >> depth;
        conditions.clear();
        compares.clear();
        for(int i=0, a, b;i<conds;i++){
            ull in;
            cin >> in >> a >> b;
            pii p(a,b);
            // def Build array of inputs
            vector<int> temp;
            stack<int> dig;
            while(in){
                dig.push(in % 10);
                in /= 10;
            }
            while(!dig.empty()){
                temp.push_back(dig.top());
                dig.pop();
            }
            conditions.push_back(temp);
            // end def
            compares.push_back(p);
        }
        int cnt = 0, ar[depth];
        vector<pii>cmp_results;
        for(int i=0;i<depth;i++){ar[i] = -2;}
        for(int i=0;i<conds;i++){
            pii re(0,0);
            cmp_results.push_back(re);
        }
        enum_numbers(ar, 0, cmp_results, cnt);
        cout << cnt << '\n';
    }
    return 0;
}
//------------------------------------------------
pii calc_new_sim(int n, int pos, vector<int> cmp){
    int ca = 0, cb = 0, len = cmp.size();
    for(int i=0;i<len;i++){
        if(pos == i && n == cmp[i])ca++;
        else if(n == cmp[i])cb++;
    }
    pii p(ca, cb);
    return p;
}
