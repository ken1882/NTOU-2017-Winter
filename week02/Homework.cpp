#include <iostream>

using namespace std;

int abs(int n){
    return n < 0 ? -1 * n : n;
}

void partation(int &num, int &a, int &b, bool &flag){
    if(flag){
        a += num % 10;
    }
    else{
        b += num % 10;
    }
    num /= 10;
    flag ^= 1;
}

int main(int argc, char** argv){
    int n;
    cin >> n;
    while(n--){
        int num, a = 0, b = 0;
        bool flag = false;
        cin >> num;
        cout << num << " is ";
        while(num){partation(num, a, b, flag);}
        cout << (abs(a-b)%11 ? "not " : "") << "a multiple of 11\n";
    }
    return 0;
}
