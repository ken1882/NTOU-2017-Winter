#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    double pos[3];
    while(cin >> pos[0] >> pos[1] >> pos[2]){
        double sum = 0, in;
        for(int i=0;i<3;i++){
            cin >> in;
            sum += (in - pos[i]) * (in - pos[i]);
        }
        cout << fixed << setprecision(2) << sqrt(sum) << '\n';
    }
    return 0;
}
