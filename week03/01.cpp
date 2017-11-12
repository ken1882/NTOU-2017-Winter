#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
    while(cin >> argc){
        cout << ((argc&1) ? "odd" : "even") << '\n';
    }
    return 0;
}
