#include <iostream>
#include <iomanip>

using namespace std;

double calc_BMI(auto cm, auto kg){
    return kg * 10000.0 / cm / cm;
}

int main(int argc, char* argv[]){
    ios::sync_with_stdio(false);
    double height, weight;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.precision(2);
    while(cin >> height >> weight){
        cout << calc_BMI(height, weight) << '\n';
    }
    return 0;
}
