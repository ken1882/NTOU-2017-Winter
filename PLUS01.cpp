#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <bitset>

using namespace std;

typedef unsigned long long int ull;

map<char, string> table;
map<string, int> dp;
map<string, set<string>> subsdp;

void build_table();

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
    for(int i = 0; i <= loc ;i++){
        pa += code[i];
    }
    for(int i = loc + slen; i < tlen; i++){
        pb += code[i];
    }
}

bool code_valid(string code){
    for(auto it:table){
        if(it.second == code)return true;
    }
    return false;
}

void substring(string str, set<string> &subs){
    int len = str.length();
    for(int start=0;start<len;start++){
        for(int rear=0;rear<len;rear++){
            string gen = "";
            for(int i=start;i<=rear;i++){
                gen += str[i];
            }
            if(gen != "")subs.insert(gen);
        }
    }
}

vector<ull> dpp[65][65];

void permutation(int n){
    vector<ull> p;
    p.push_back(0);
    dpp[1][0] = p;
    p.push_back(1);
    dpp[2][1] = p;

    for(int i = 3; i < n-1;i++){
        vector<ull> ar; ull flag = 1;
        for(int j = 0;j < i-1;j++){
            ar.push_back(flag);
            flag *= 2;
        }
        dpp[i][1] = ar;
        for(int j = 2;j < i - 1;j++){
            vector<ull> pos = dpp[i-1][j], pos2 = dpp[i-1][j-1];
            for(auto value:pos2){
                bitset<64> bt(value);
                bt[i-2] = 1;
                pos.push_back(bt.to_ulong());
            }
            dpp[i][j] = pos;
            cout << i << ','<< j << ':' << pos.size() << endl;
        }
        ar.clear(); ar.push_back(pow(2, i-1) - 1);
        dpp[i][i-1] = ar;
    }
}


int main(int argc, char** argv){
    ull sol;
    build_table();
    string symbol, code;
    string part_a = "", part_b = "";
    vector<vector<string>> vvs;
    ull sum = 1, div = 1;
    ull c = 24, n = 13;
    for(ull i=1;i<=n;i++){
        div *= i;
    }
    for(ull i=c;i > c-n;i--){
        sum *= i;
    }
    cout << sum / div << endl;
    permutation(28);
    while(cin >> code);
    /*
    while(cin >> symbol >> code){
        set<string> code_subs;
        substring(code, code_subs);
        for(auto str:code_subs){
            if(code_valid(str)){dp[str] = 1;}

        }
        cout << dp[code] << '\n';
    } // while cin
    */
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
