#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(){
    int cas;
    cin >> cas;
    while(cas--){
        int n;
        cin >> n;
        int sq = n*n, mod = sq - 1;
        vector<float> ar;
        float in;
        for(int i=0;i<sq;i++){
            cin >> in;
            ar.push_back(in);
        }
        for(int i=0, index = 0;i<sq;i++){
            if(i+1 == sq){
                printf(",%.2f\n", ar[i]);
                continue;
            }
            index = (i * n) % mod;
            if(i % n){printf(",");}
            else if(i){printf("\n");}
            printf("%.2f",ar[index]);
        }
    }
    return 0;
}
/*
2
2
1 2 3 4
3
1 2 3 4 5 6 7 8 9
*/
