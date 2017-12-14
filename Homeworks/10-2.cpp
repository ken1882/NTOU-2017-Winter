#include <iostream>
#include <vector>
#include <algorithm>
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

bool sort_pt(Point a, Point b){
    if(a.x == b.x)return a.y < b.y;
    return a.x < b.x;
}

int main(){
    int cas;
    while(cin >> cas){
        vector<Point> data;
        for(int i=0;i<cas;i++){
            float a, b;
            cin >> a >> b;
            Point p(a,b);
            data.push_back(p);
        }
        sort(data.begin(), data.end(), sort_pt);
        for(auto p:data){
            cout << fixed << setprecision(2) << p.x << ' ' << p.y << '\n';
        }
    }
    return 0;
}
