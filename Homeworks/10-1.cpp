#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>

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

struct Circle:Point{

    float radius;
    const float delta = 0.00001;

    Circle(float a, float b, float rad = 1):Point(a,b){
        radius = rad;
    }

    float distance_to(float a, float b){
        return hypot(x-a, y-b);
    }

    int pt_loc(float a, float b){
        float dis = distance_to(a, b), gate = radius;

        float re = dis - gate;
        if(re > delta){
            return -1;
        }
        if(re < -delta){
            return 1;
        }
        return 0;
    }
};

int main(){
    int cas;
    while(cin >> cas){
        float x, y, r;
        cin >> x >> y >> r;
        Circle c(x,y,r);
        for(int i=0;i<cas;i++){
            cin >> x >> y;
            cout << c.pt_loc(x,y) << '\n';
        }
    }
    return 0;
}
