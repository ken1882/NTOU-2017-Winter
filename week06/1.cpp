#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main(){
    string str;
    while(getline(cin, str)){
        int len = str.length();
        for(int i=0;i<len;i++){
            if(str[i] == ',')str[i] = ' ';
        }
        stringstream ss(str);
        double n;
        vector<double> nums;
        while(ss >> n){
            nums.push_back(n);
        }
        len = nums.size();

        pair<int, int> maxpos(0,0);
        double maxn = -2147483648;
        for(int i=0;i<len-1;i++){
            for(int j=i+1;j<len;j++){
                double base = nums[i] + nums[j];
                double result = nums[i] * nums[j] / base / base;
                if(result > maxn){
                    maxpos.first = i; maxpos.second = j;
                    maxn = result;
                }
            }
        }
        cout << '(' << maxpos.first << ',' << maxpos.second << ")\n";
    }
    return 0;
}
