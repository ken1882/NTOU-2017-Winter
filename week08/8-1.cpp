#include <iostream>
#include <cstdio>

using namespace std;

int get_color_point(char color){
    switch(color){
    case 'S':
        return 1;
    case 'D':
        return 2;
    case 'H':
        return 3;
    case 'C':
        return 4;
    default:
        return 0;
    }
}

int get_number_point(char n){
    switch(n){
    case 'J':
        return 11;
    case 'Q':
        return 12;
    case 'K':
        return 13;
    case 'A':
        return 14;
    default:
        return n - '0';
    }
}

int get_point(char n, char color){
    return get_number_point(n) * 10 + get_color_point(color);
}

int main(){
    int cas;
    cin >> cas;
    while(cas--){
        string card;
        cin >> card;
        int a = get_point(card[0], card[1]), b = get_point(card[2], card[3]);
        cout << (a > b) << '\n';
    }
    return 0;
}
