#include <iostream>
#include <cstdio>
#include <bitset>
#include <map>

using namespace std;

const int Finger = 10;

typedef bitset<Finger+1> sax;
map<char, sax> table;

void build_table();

int main(){
    build_table();
    int cas;
    string sequence;
    cin >> cas;
    getline(cin, sequence);
    while(cas--){
        getline(cin, sequence);
        sax finger(0);
        int cnt[Finger+1] = {0};
        for(auto ch:sequence){
            for(int i=1;i<=Finger;i++){
                if(finger[i] ^ table[ch][i]){
                    finger[i] = table[ch][i];
                    if(finger[i])cnt[i]++;
                }
            }
        }
        for(int i=1, first = 1;i<=Finger;i++){
            if(!first){cout << ' ';}
            first = false;
            cout << cnt[i];
        }
        cout << '\n';
    }
    return 0;
}

void build_table(){
    table['c'] = sax(0x79c); // 11110011100
    table['d'] = sax(0x39c); // 01110011100
    table['e'] = sax(0x19c); // 00110011100
    table['f'] = sax(0x09c); // 00010011100
    table['g'] = sax(0x01c); // 00000011100
    table['a'] = sax(0x00c); // 00000001100
    table['b'] = sax(0x004); // 00000000100

    table['C'] = sax(0x008); // 00000001000
    table['D'] = sax(0x39e); // 01110011110
    table['E'] = sax(0x19e); // 00110011110
    table['F'] = sax(0x09e); // 00010011110
    table['G'] = sax(0x01e); // 00000011110
    table['A'] = sax(0x00e); // 00000001110
    table['B'] = sax(0x006); // 00000000110
}
