#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <functional>

using namespace std;

typedef pair<int, int> pii;

/*======================================*
 *  This class holds the positions of
 * given block, require operator and goal.
 *======================================*/
struct Block{
    vector<pii> nums; // Positions
    char _operator;
    int goal;

    Block(){
        _operator = '\0';
        goal = 0;
    }

    void print_info(){
        cout << "-------------------\n";
        cout << "Pos:\n";
        for(auto i:nums){
            cout << i.first << ' ' << i.second << '\n';
        }
        cout << "Operator and goal: " << _operator << ' ' << goal << '\n';
    }
};

const int maxn = 6+1;

// Table of numbers
int table[maxn][maxn];

// Directly access the parent block of given position
map< pii, vector<Block*> > blocks;

// Object pool
vector<Block*> pool;

void print_answer(){
    for(int i=1;i<maxn;i++){
        cout << table[i][1];
        for(int j=2;j<maxn;j++){
            cout << table[i][j];
        }
        cout << '\n';
    }
}

// Return the number in table by position
int get_number(pii p){
    return table[p.second][p.first];
}

// Used number boolean table, same row or col cannot has same number
bool used_row[maxn][maxn], used_col[maxn][maxn];

// Determine whether the parent block is a possible solution by position
bool determine_block_possible(pii p){

    for(auto bk:blocks[p]){
        char op  = bk -> _operator;
        int goal = bk -> goal;

        // '=' only has one pos, directly return result
        if(op == '='){
            int n = get_number(p);
            return n == goal;
        }


        if(op == '-' || op == '/'){
            pii pa = bk -> nums[0], pb = bk -> nums[1];
            int a = get_number(pa), b = get_number(pb);

            // Block incomplete, still possible
            if(a == 0 || b == 0)return true;
            if(op == '-'){
                return (a-b) == goal || (b-a) == goal;
            }
            else{
                return a == goal * b || b == goal * a;
            }
        }

        int sum = op == '*' ? 1 : 0;
        bool completed = true;
        for(auto pi:bk -> nums){
            int n = get_number(pi);
            if(n == 0){
                completed = false;
                continue;
            }
            switch(op){
            case '+':
                sum += n; break;
            case '*':
                sum *= n; break;
            }

            // current sum larger than goal, so its impossible
            // even if its incomplete
            if(sum > goal){
                return false;
            }
        }
        // If block is completed, determine sum equal to goal
        if(completed && sum != goal)return false;
    }
    return true;
}

bool all_block_passed(){
    int n = (maxn-1) * (maxn-1);
    for(int i=0;i<n;i++){
        int curx = i % (maxn-1) + 1;
        int cury = i / (maxn-1) + 1;
        pii p(curx, cury);
        if(!determine_block_possible(p)){
            return false;
        }
    }
    return true;
}

void backtrack(int cnt){
    // Current position in table
    int curx = cnt % (maxn-1) + 1;
    int cury = cnt / (maxn-1) + 1;

    // Final position reached
    if(cnt == (maxn-1) * (maxn-1)){
        if(all_block_passed()){
            return print_answer();
        }
    }
    //cout << cnt << endl; // Debug usage
    for(int n=1;n<maxn;n++){
        if(used_row[curx][n] || used_col[cury][n])continue;
        used_row[curx][n] = 1;
        used_col[cury][n] = 1;
        table[cury][curx] = n;
        pii p(curx, cury);
        bool passed = true;
        if(determine_block_possible(p)){
            backtrack(cnt + 1);
        }
        table[cury][curx] = 0;
        used_row[curx][n] = 0;
        used_col[cury][n] = 0;
    }
}

// Free objects
void clean_pool(){
    for(auto obj:pool){
        delete obj;
    }
    pool.clear();
}

// Initialize
void init(){
    blocks.clear();
    memset(used_row,0,sizeof(used_row));
    memset(used_col,0,sizeof(used_col));
    memset(table,0,sizeof(table));
}

int main(){
    int conds;
    while(cin >> conds){
        init();
        for(int c=0;c<conds;c++){
            int n, x, y;
            cin >> n;

            // Create new instance of the block and store to pool
            Block* bk = new Block();
            pool.push_back(bk);

            // input positions of the block
            for(int i=0;i<n;i++){
                cin >> y >> x;
                pii p(x,y);
                bk -> nums.push_back(p);

                // blocks[position] => original block parent
                blocks[p].push_back(bk);
            }
            cin >> bk -> goal >> bk -> _operator;
        }

        for(auto obj:pool){
            //obj -> print_info();
        }

        backtrack(0);
        clean_pool();
    }
    return 0;
}

/*
16
3 1 1 1 2 2 1 12 +
4 1 3 1 4 1 5 2 5 32 *
2 1 6 2 6 3 -
2 2 2 3 2 4 -
2 2 3 2 4 7 +
2 3 1 4 1 3 +
2 3 3 3 4 15 *
2 3 5 3 6 2 -
2 4 2 5 2 3 /
2 4 3 4 4 1 -
2 4 5 4 6 2 /
3 5 1 6 1 6 2 80 *
3 5 3 5 4 6 4 12 *
2 5 5 6 5 4 -
2 5 6 6 6 3 /
1 6 3 6 =
20
2 1 2 1 4 2 /
2 5 6 6 1 6 /
2 5 6 5 3 2 -
2 5 6 6 5 2 /
2 5 3 2 1 1 /
2 5 4 2 6 3 *
6 5 4 2 5 2 3 6 3 1 1 3 1 360 *
2 6 1 2 5 5 -
2 6 1 2 5 6 /
2 3 5 2 5 3 /
2 3 1 1 5 1 -
2 6 2 2 3 5 /
2 6 2 3 3 1 -
2 6 2 4 5 5 /
4 5 6 2 1 3 2 1 5 18 +
2 2 2 2 1 2 -
6 2 2 4 4 1 1 2 6 1 3 1 4 864 *
3 2 2 4 2 1 1 14 +
4 5 6 1 1 6 6 5 2 432 *
4 5 6 1 1 6 6 5 2 19 +
*/
