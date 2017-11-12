#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char** argv){
    int n, maxn, minn;
    ios::sync_with_stdio(false);
    while(cin >> n >> minn >> maxn){
        if(minn > maxn)swap(minn, maxn);
        int offset = minn;
        int counter[110];
        memset(counter, 0, sizeof(counter));

        for(int i=0, in;i<n;i++){
            cin >> in;
            counter[in - offset] += 1;
        }

        for(int i=0;i <= maxn - minn;i++){
            cout << i + offset << " appears " << counter[i] << " times\n";
        }
    }
    return 0;
}
