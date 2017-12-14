#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(int argc, char** argv){
    int n;
    while(cin >> n){
        vector<int> ar;
        for(int i=0, in;i<n;i++){
            cin >> in;
            ar.push_back(in);
        }
        sort(ar.begin(), ar.end());
        int target, cnt = 0, cas = 0;

        while(cin >> target){
            cas++;
            int low = 0, hi = n-1;
            bool found = false;
            while(low <= hi){
                int mid = (low + hi) / 2;
                cnt++;
                if(target > ar[mid]){
                    low = mid + 1;
                }
                else if(target < ar[mid]){
                    hi = mid - 1;
                }
                else{
                    found = true;
                    break;
                }
            }
            cout << (found ? "yes" : "no" ) << '\n';
        }
        cout << fixed << setprecision(2) << ((float)cnt / cas) << '\n';
    }
    return 0;
}

//1 7 3 4 5 6
