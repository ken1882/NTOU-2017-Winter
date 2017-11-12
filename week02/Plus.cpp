#include <iostream>
#include <sstream>
#include <cstdio>

using namespace std;

int main(int argc, char** argv){
    int loop, cnt = 0;
    string input;
    cin >> loop; getchar();

    while(cnt++ < loop && cin >> input){
        int n, sum = 0;
        bool flag = true;
        int a[n]={0};
        stringstream ss(input);
        while(ss >> n){
            sum += flag ? n : -1 * n;
            flag ^= 1;
        }
        cout << input << " is ";
        cout << (sum % 11 ? "not a " : "a ");
        cout << "multiple of 11\n";
    }
    return 0;
}
