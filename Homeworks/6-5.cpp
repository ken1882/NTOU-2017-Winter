#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char** argv){
    ios::sync_with_stdio(false);
    int cas;
    cin >> cas;
    while(cas--){
        int n;
        cin >> n;
        vector<int>house;
        for(int i=0,in;i<n;i++){
            cin >> in;
            house.push_back(in);
        }
        nth_element(house.begin(), house.begin() + n/2, house.end());
        int loc = house[n/2], sum = 0;
        for(auto pos:house)sum += abs(loc - pos);
        cout << sum << '\n';
    }
    return 0;
}
