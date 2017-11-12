#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(){
    //ios::sync_with_stdio(false);
    int cas;
    cin >> cas;
    while(cas--){
        int ord;
        cin >> ord;
        vector<double> ar;
        double input;
        for(int i=0;i<ord+1;i++){
            cin >> input;
            ar.push_back(input);
        }
        int calc_n;
        cin >> calc_n;
        while(calc_n--){
            double sum = ar[0];
            double base;
            cin >> base;
            double mul = base;
            for(int i=1;i<=ord;i++){
                sum += mul * ar[i];
                mul *= base;
            }
            printf("%.2F\n", sum);
        }
    }
    return 0;
}
/*
2
3 1 2 3 4
2 1 2
3 0 1 0 1
2 -1 2
*/
