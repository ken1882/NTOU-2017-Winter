#include <iostream>
#include <cstdio>

using namespace std;


struct Point{
    float x, y;

    Point(float a, float b){
        moveto(a,b);
    }

    void moveto(float a,float b){
         x = a; y = b;
    }
};

struct Rect:Point{
    float width, height;

    Rect(float a, float b, float w, float h):Point(a,b){
        width = w; height = h;
    }

    bool collision(float a, float b){
        if(a < x || b < y){return false;}
        if(a > x + width || b > y + height){return false;}
        return true;
    }
};

int main(){
    float x, y, w, h;
    while(cin >> x >> y >> w >> h){
        Rect rect(x, y, w, h);
        int cas;
        cin >> cas;
        for(int i=0;i<cas;i++){
            cin >> x >> y;
            bool coll = rect.collision(x,y);
            printf("point (%.2f,%.2f) %s in the rectangle\n", x, y, coll ? "is": "is not");
        }
    }
    return 0;
}
/*
-9.000000 17.000000 35.000000 1.000000
10
-22 224
-36 462
-219 -355
-9 461
327 442
104 -109
3 17
17 17
-53 395
38 271
1 6 4 4
3
5 8
0 2
1 1
*/

