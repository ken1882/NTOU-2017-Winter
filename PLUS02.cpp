#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

typedef unsigned long long ull;

void build_table();

map<char, string> table;

// i: string length, j: partition point count
ull dp[101][101] = {{0}};

bool partition_valid(int len, int pt){
    pt += 1;
    return pt * 5 >= len;
}

void permutation(int depth = 100){
    for(int i = 3;i <= depth; i++){
        if(partition_valid(i, 1))dp[i][1] = i - 1;
        for(int j = 2; j < i - 1;j++){
            if(!partition_valid(i, j))continue;
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        }
        dp[i][i-1] = 1;
    }
}

string transmit(string str){
    string result = "";
    for(auto ch:str){
        result += table[toupper(ch)];
    }
    return result;
}

void partation(string symbol, string code, string &pa, string &pb){
    symbol = transmit(symbol);
    int loc = code.find(symbol);
    int slen = symbol.length(), tlen = code.length();

    for(int i = 0; i < loc ;i++){
        pa += code[i];
    }
    for(int i = loc + slen; i < tlen; i++){
        pb += code[i];
    }
}

string decode(string code){
    string index = "";
    cout << code << endl;
    int len = code.length();
    int part_cnt = (len + 4) / 5;
    for(int i=0, init_flag = 0;i < part_cnt;i++){
        pair<char, int> longest;
        longest.first = '\0'; longest.second = 0;
        for(auto it:table){
            int flag = init_flag, flag2 = 0, len2 = it.second.length();
            string cur = ""; cur += code[flag];
            string cmp = ""; cmp += it.second[flag2];
            while(cmp == cur && flag < len && flag2 < len2){
                cmp += it.second[++flag2]; cur += code[++flag];
            }
            if(flag2 == len2 && flag2 >= longest.second){
                longest.first = it.first;
                longest.second = flag2;
            }
        }// for it in talbe
        index += longest.first;
        init_flag += longest.second;
    }// enum partition count
    return index;
} // todo: change to search for partition loc

int main(int argc, char **argv){
    build_table();
    dp[1][0] = 1;
    dp[2][1] = 1;
    dp[3][1] = 2;
    permutation();
    string symbol, code;

    while(cin >> symbol >> code){
        string pa = "", pb = "";
        partation(symbol, code, pa, pb);
        string ans; ans += decode(pa); ans += decode(pb);
        cout << ans << endl;
    }
    return 0;
}

void build_table(){
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
