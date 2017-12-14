#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv){
    int n;
    while(cin >> n){
        vector<int> ar;
        for(int i=0, in;i<n;i++){
            cin >> in;
            ar.push_back(in);
        }

        for(int i=1;i<n;i++){
            for(int j=i;j>0;j--){
                if(ar[j] < ar[j-1]){
                    swap(ar[j], ar[j-1]);
                }
                else{break;}
            }
        }

        for(int i=0;i<n-1;i++){
            cout << ar[i];
        }
        cout << ar[i-1] << '\n';
    }
    return 0;
}
