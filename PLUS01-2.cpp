#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

typedef unsigned long long ull;

void build_table();

map<char, string> table;

// i: string length, j: partition point count
ull dp[101][101] = {{0}};

string transmit(string str){
    string result = "";
    for(auto ch:str){
        result += table[toupper(ch)];
    }
    return result;
}

bool partition_valid(int len, int pt){
    pt += 1;
    return pt * 5 >= len;
}

void permutation(int depth = 100){
    for(int i = 1; i <= depth; i++){
        dp[i][0] = 1;
    }
    for(int i = 3;i <= depth; i++){
        dp[i][1] = i - 1;
        for(int j = 2; j < i - 1;j++){
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        }
        dp[i][i-1] = 1;
    }
}

void enum_symbol_loc(string symbol, string code, vector<int> &out){
    int flag = 0, clen = code.length();
    while(flag < clen){
        auto str = code.substr(flag, clen - flag);
        auto loc = str.find(symbol);
        if(loc == string::npos){
            break;
        }
        else{
            out.push_back(loc + flag);
            flag = flag + loc + 1;
        }
    }
}

void partation(int sym_loc, int sym_len, string code, string &pa, string &pb){
    int flag_pt = 0, clen = code.length();
    if(sym_loc != 0){
        pa = code.substr(0, sym_loc);
        flag_pt = sym_loc + sym_len;
    }
    else{flag_pt = sym_len;}

    if(flag_pt + sym_len <= clen){
        pb = code.substr(flag_pt, clen - flag_pt);
    }
}

int main(int argc, char **argv){
    build_table();
    dp[1][0] = 1;
    dp[2][1] = 1;
    dp[3][1] = 2;
    permutation();
    string symbol, code;
    //cout << transmit("IRISH") << endl;
    while(cin >> symbol >> code){
        int len = code.size();
        vector<int> sym_locs;
        symbol = transmit(symbol);
        enum_symbol_loc(symbol, code, sym_locs);
        int slen = symbol.length();
        cout << symbol << endl;
        ull sumf = 0;
        for(auto pt:sym_locs){
            string head, rear;
            partation(pt, slen, code, head, rear);

            ull sumh = 0, sumr = 0;
            int lenh = head.length(), lenr = rear.length();
            cout << head << endl << rear << endl;
            cout << lenh << ' ' << lenr << endl;
            for(int i=0;i<lenh;i++){
                if(!partition_valid(lenh, i))continue;
                cout << i << ' ' << dp[lenh][i] << endl;
                sumh += dp[lenh][i];
            }
            for(int i=0;i<lenr;i++){
                if(!partition_valid(lenr, i))continue;
                cout << i << ' ' << dp[lenr][i] << endl;
                sumr += dp[lenr][i];
            }
            if(sumh == 0)sumh |= 1;
            if(sumr == 0)sumr |= 1;
            cout << sumh << ' ' << sumr << endl;
            sumf += sumh * sumr;
        }
        cout << sumf << endl;
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
