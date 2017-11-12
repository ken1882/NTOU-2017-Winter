#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

map<char, string> table;

string spacing();
void build_table();

int main(){
    //ios::sync_with_stdio(false);
    build_table();
    char ch, last_ch;
    bool first = true;
    while(ch = getchar()){
        if(ch == 10)break;
        if(!first && (('A' <= ch && ch <= 'Z') || ('0' <= ch && ch <= '9')) && last_ch != ' '){
            printf(" ");
        }
        first = false;
        printf("%s", table[ch].c_str());
        last_ch = ch;
    }
    return 0;
}

string spacing(){
    return "       "; // ' ' * 7
}

void build_table(){
    table[' '] = spacing();
    table['A'] = ".-";
    table['B'] = "-...";
    table['C'] = "-.-.";
    table['D'] = "-..";
    table['E'] = ".";
    table['F'] = "..-.";
    table['G'] = "--.";
    table['H'] = "....";
    table['I'] = "..";
    table['J'] = ".---";
    table['K'] = "-.-";
    table['L'] = ".-..";
    table['M'] = "--";
    table['N'] = "-.";
    table['O'] = "---";
    table['P'] = ".--.";
    table['Q'] = "--.-";
    table['R'] = ".-.";
    table['S'] = "...";
    table['T'] = "-";
    table['U'] = "..-";
    table['V'] = "...-";
    table['W'] = ".--";
    table['X'] = "-..-";
    table['Y'] = "-.--";
    table['Z'] = "--..";
    table['0'] = "-----";
    table['1'] = ".----";
    table['2'] = "..---";
    table['3'] = "...--";
    table['4'] = "....-";
    table['5'] = ".....";
    table['6'] = "-....";
    table['7'] = "--...";
    table['8'] = "---..";
    table['9'] = "----.";
}
