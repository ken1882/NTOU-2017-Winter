
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        for(int i=0;i<n-1;i++){
            for(int j=0, temp;j<n-1-i;j++){
                if(a[j] > a[j+1]){
                    temp = a[j+1];
                    a[j+1] = a[j];
                    a[j] = temp;
                }
            }
        }
        for(int i=0;i<n;i++){
            cout << a[i] << '\n';
        }
    }
    return 0;
}

