#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <cmath>
#include <algorithm>

using namespace std;

#define Bits 200

/**================================================================================*
 *  > BigNum
 * --------------------------------------------------------------------------------
 *  Big Number calculation, support up to defined bits: 1000
 *================================================================================**/
class BigNum{
public:
    /*-----------------------------------------------------------------------*
     *  > Public Instance Variable
     *-----------------------------------------------------------------------*/
    int digit[Bits];        // digit
    int record;             // record the position of first element
    bool negative;          // Negative?
    /*-----------------------------------------------------------------------*
     *  > Object Initialization
     *-----------------------------------------------------------------------*/
    BigNum(string number = "0"){
        record = 0;
        negative = false;
        set_number(number);
    }
    /*-----------------------------------------------------------------------*
     *  > Set initial number
     *-----------------------------------------------------------------------*/
    void set_number(string num){
        memset(digit,0,sizeof(digit));
        if(num[0] == '-')negative = true;
        record = num.length() - 1 - negative;
        for(int i = record, cnt = negative; i >= 0 ; i--){
            digit[i] = num[cnt++] - 48;
        }
    }
    /*-----------------------------------------------------------------------*
     *  > Display number
     *-----------------------------------------------------------------------*/
    void show(bool textwrap = true){
        if(negative)printf("-");
        for(int i = record;i >=0 ;i--)printf("%d",digit[i]);
        if(textwrap)puts("");
    }
    /*-----------------------------------------------------------------------*
     *  > Absolute Number, maybe useless
     *-----------------------------------------------------------------------*/
    void abs_index(){
        for(int i=0;i<=record;i++)
            if(digit[i] < 0)digit[i] *= -1;
    }
    /*-----------------------------------------------------------------------*
     *  > Integer to BigNum
     *-----------------------------------------------------------------------*/
    BigNum itobig(int num){
        stack<int> ch;
        int cnt = -1;
        while(num){
            ch.push(num%10);
            num /= 10;
            cnt++;
        }
        BigNum cache;
        cache.record = cnt;
        while(!ch.empty()){
            cache.digit[cnt--] = ch.top();
            ch.pop();
        }
        return cache;
    }
    /*-----------------------------------------------------------------------*
     *  > Compare BigNum
     *-----------------------------------------------------------------------*/
    int compare_number(BigNum num){
        for(int i= record; i>= 0;i--){
            if(digit[i] > num.digit[i])return 1;            // bigger
            if(digit[i] < num.digit[i])return -1;           // lower
            if(i == 0 && digit[i] == num.digit[i])return 0; // equal
        }
    }
    /*-----------------------------------------------------------*/
    bool operator >(BigNum num){
        bool result = record > num.record;
        bool same   = record == num.record;
        if(same){
            result = compare_number(num) > 0;
        }
        return result;
    }
    /*-----------------------------------------------------------*/
    bool operator <(BigNum num){
        bool result = record < num.record;
        bool same   = record == num.record;
        if(same){
            result = compare_number(num) < 0;
        }
        return result;
    }
    /*-----------------------------------------------------------*/
    bool operator ==(BigNum num){
        bool result = (record == num.record);
        if(result){
            result = compare_number(num) == 0;
        }
        return result;
    }
    /*-----------------------------------------------------------*/
    bool operator >=(BigNum num){
        return ((*this > num) || (*this == num));
    }
    /*-----------------------------------------------------------*/
    bool operator <=(BigNum num){
        return ((*this < num) || (*this == num));
    }
    /*-----------------------------------------------------------*/
    BigNum operator =(BigNum num){
        negative = num.negative;
        record = num.record;
        memset(digit,0, sizeof(digit));
        for(int i=0;i<=num.record;i++){
            digit[i] = num.digit[i];
        }
    }
    /*-----------------------------------------------------------*/
    BigNum operator +=(BigNum num){
        int cap = max(record, num.record);
        if(num.negative){
            negative = *this > num;
            *this -= num;
        }
        else{
            for(int i=0;i <= cap;i++){
                record = i;
                digit[i] += num.digit[i];
                if(digit[i] >= 10){
                    digit[i+1]++;
                    digit[i] -= 10;
                    record++;
                }
            }
        }
    }
    /*-----------------------------------------------------------*/
    BigNum operator +=(int num){
        stack<int> deg;
        while(num){
            deg.push(num % 10);
            num /= 10;
        }
        int i = 0;
        while(!deg.empty()){
            digit[i] += deg.top();  deg.pop();
            if(digit[i] >= 10){
                digit[i+1]++;
                digit[i] -= 10;
                record = max(record, i+1);
            }
        }
    }
    /*-----------------------------------------------------------*/
    BigNum operator -=(BigNum num){
        if(*this < num){
            BigNum temp = *this;
            *this = num;
            *this -= temp;
            negative = true;
        }
        else{
            int cap = max(record, num.record);
            for(int i = 0;i <= cap;i++){
                digit[i] -= num.digit[i];
                if(digit[i] < 0){
                    digit[i+1]--;
                    digit[i] += 10;
                }
                if(digit[i] > 0){
                    record = i;
                }
            }
        }
        while(digit[record] == 0)record--;
    }
    /*-----------------------------------------------------------*/
    BigNum operator *(BigNum num){
        int cache[Bits << 1 | 1] = {0};
        int bit = record + num.record + 1;
        BigNum temp;

        for(int i=0;i<=num.record;i++){
            for(int j=0;j<=record;j++){
                cache[i+j] += num.digit[i] * digit[j];
            }
        }
        for(int i=0;i <= bit;i++){
            temp.record = i;
            if(cache[i] >= 10){
                cache[i+1] += cache[i] / 10;
                cache[i] %= 10;
                temp.record++;
            }
            temp.digit[i] = cache[i];
            if(i == bit && cache[i] == 0)temp.record--;
        }
        return temp;
    }
    /*-----------------------------------------------------------*/
    BigNum operator *=(BigNum num){
        *this = *this * num;
    }
    /*-----------------------------------------------------------*/
    BigNum operator /=(BigNum num){
        if(num > *this){
            *this = BigNum();
        }
        else{
            int mul = record - num.record;
            BigNum cache;
            BigNum quotient;
            while(*this >= num){
                for(int i = 9; i >= 0;i--){
                    BigNum sub = itobig(i);
                    for(int j = 0;j < mul;j++)sub *= itobig(10);
                    cache = num * sub;

                    if(*this >= cache){
                        *this -= cache;
                        quotient += sub;
                        mul--;
                        break;
                    }
                }
            }
            *this = quotient;
        }
    }
    /*-----------------------------------------------------------*/
};

BigNum itobig(int num){
    BigNum cache;
    return cache.itobig(num);
}

bool lesser(BigNum a, BigNum b){
    if(a.negative){
        if(b.negative)return a > b;
        else return true;
    }
    else{
        if(b.negative)return false;
        else return a < b;
    }

}

int main(int argc, char* argv[]){
    int n;
    cin >> n;
    while(n--){
        BigNum top, mod, top2, temp;
        int sum = 0;
        string a, b;
        cin >> a >> b;
        top.set_number(a);
        mod.set_number(b);
        top2  = top; top2 += 1;
        top2 *= top;
        top2 /= itobig(2);
        top = top2;
        top /= mod;
        top *= mod;
        top2 -= top;
        top2.show();
        //cout << (((1 + top) * top / 2) % mod) << '\n';
    }
    return 0;
}
