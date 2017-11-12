#include <iostream>

using namespace std;

string get_bmi_str(float num){
    if(num >= 35)return "obese class III";
    if(num >= 30)return "obese class II";
    if(num >= 27)return "obese class I";
    if(num >= 24)return "overweight";
    if(num >= 18.5)return "normal";
    return "underweight";
}
int main(int argc, char** argv){
    ios::sync_with_stdio(false);
    float weight, height;
    while(cin >> weight >> height){
        height /= 100.0;
        float bmi = weight / height / height;
        bmi = (int)(bmi * 100 + 0.5) / 100.0;
        cout << "BMI:" << bmi << " Category:" << get_bmi_str(bmi) << '\n';
    }
    return 0;
}
