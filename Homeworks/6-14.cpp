#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct POS{
    int x,y;

    POS(int a, int b){
        x = a; y = b;
    }

    void moveto(int _x, int _y){
        x = _x; y = _y;
    }
};

bool collision(int x1, int y1, int x2, int y2){
    if(x1 == x2)return true;
    if(y1 == y2)return true;
    if(x1+y1 == x2+y2)return true;
    if(x1-y1 == x2-y2)return true;
    return false;
}

int main(){
    int cas;
    cin >> cas;

    const string Output[] = {"invalid configuration", "valid configuration"};

    while(cas--){
        int len;
        cin >> len;
        vector<POS> pieces;

        bool passed = true;
        for(int i=0,x,y;i<len;i++){
            cin >> x >> y;
            POS pos(x, y);
            for(int j=0;j<i && passed;j++){
                pos = pieces[j];
                if(collision(x, y, pos.x, pos.y)){
                    passed = false; break;
                }
            }
            if(passed){
                pos.moveto(x, y);
                pieces.push_back(pos);
            }
        }

        cout << Output[passed] << '\n';
    }
    return 0;
}

