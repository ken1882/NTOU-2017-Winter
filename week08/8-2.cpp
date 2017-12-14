#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

double matrix[3][3];
double inverse[3][3];

double calc_abs(){
    double base = matrix[0][0] * matrix[1][1] * matrix[2][2];
    base += matrix[1][0] * matrix[2][1] * matrix[0][2];
    base += matrix[0][1] * matrix[1][2] * matrix[2][0];
    base -= matrix[0][2] * matrix[1][1] * matrix[2][0];
    base -= matrix[0][1] * matrix[1][0] * matrix[2][2];
    base -= matrix[0][0] * matrix[1][2] * matrix[2][1];
    return base;
}

double calc_inverse(){
    inverse[0][0] = matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1];
    inverse[0][1] = matrix[0][2] * matrix[2][1] - matrix[0][1] * matrix[2][2];
    inverse[0][2] = matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1];
    inverse[1][0] = matrix[1][2] * matrix[2][0] - matrix[1][0] * matrix[2][2];
    inverse[1][1] = matrix[0][0] * matrix[2][2] - matrix[0][2] * matrix[2][0];
    inverse[1][2] = matrix[0][2] * matrix[1][0] - matrix[0][0] * matrix[1][2];
    inverse[2][0] = matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0];
    inverse[2][1] = matrix[0][1] * matrix[2][0] - matrix[0][0] * matrix[2][1];
    inverse[2][2] = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}

int main(){
    int cas;
    cin >> cas;
    while(cas--){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cin >> matrix[i][j];
                inverse[i][j] = 0;
            }
        }
        double abs_a = calc_abs(); calc_inverse();
        for(int i=0;i<3;i++){
            bool first = true;
            for(int j=0;j<3;j++){
                if(!first)cout << ' ';
                first = false;
                //cout << fixed << setprecision(2) << inverse[i][j]/abs_a;
                printf("%.2f ", inverse[i][j] / abs_a);
            }
            cout << '\n';
        }
    }
    return 0;
}
