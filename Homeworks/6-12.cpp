#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int cas;
    cin >> cas;
    while(cas--){
        int height, width, n;
        cin >> height >> width >> n;
        cout << height << ' ' << width << ' ' << n << '\n';
        string table[height+1];
        for(int i=0;i<height;i++){
            cin >> table[i];
            table[i] += '.';
        }
        table[height].resize(width + 1);
        for(int i=0;i<=width;i++)table[height][i] = '.';

        int sx, sy, limit = min(height, width);
        for(int i=0;i<n;i++){
            cin >> sy >> sx;
            char base = table[sy][sx];
            bool passed = true;
            //cout << sy << ' ' << sx << '\n';
            for(int i=1; passed == true ;i++){
                int ox = sx - i, oy = sy - i;
                if(ox < 0 || oy < 0){passed = false;}
                for(int cx = ox; cx <= sx + i && passed; cx++){
                    for(int cy = oy; cy <= sy + i; cy++){
                        //printf("(%d,%d):%c\n", cy, cx, table[cy][cx]);
                        if(table[cy][cx] != base){
                            passed = false; break;
                        }
                    }
                }
                if(!passed){cout << 1 + (i - 1) * 2 << '\n';}
            }

        }

    }
    return 0;
}

