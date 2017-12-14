#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

typedef pair<int, int> pii;

const int Maxn = 20;    // Max number
const int Succ = 5;     // Win condition
int table[Maxn][Maxn];  // Table Index

const int Black = 1;    // Black piece numeric
const int White = 2;    // White piece numeric

// string of above two
const string Color[] = {"", "black", "white"};

// Return the piece number in row, col
pair<int, int> piece_number_xy(int x, int y){
    int cx = 0, cy = 0;
    for(int i=0;i<Maxn;i++){
        if(table[i][x] != 0)cx++;
        if(table[y][i] != 0)cy++;
    }
    pair<int,int> re(cy, cx);
    return re;
}

// Hash xy pos to one value
int hash_pos(int x, int y){
    return y * (Maxn + 1) + x;
}

// Dehash value back to xy pos(return y,x)
pii dehash_pos(int v){
    pii p(v / (Maxn+1), v % (Maxn+1)); // (y,x)
    return p;
}

// Check position is valid
bool pos_valid(int x, int y){
    if(x < 0 || y < 0)return false;
    if(x >= Maxn || y >= Maxn)return false;
    return true;
}

// Determine whether the game is over, anyone is won in other word
bool determine_gameover(int sx, int sy, int cur_color){
    int nx[] = { 0, 0, 1,-1, 1,-1, 1,-1}; // DFS 8-direction steps
    int ny[] = { 1,-1, 0, 0, 1,-1,-1, 1}; // 2,8,6,4,3,7,9,1(numpad)
    // direction number count
    static const int Ndir = 8;

    // Initial depth
    int depth = 1;

    // DFS visited table
    bool visited[Maxn][Maxn] = {{0}};

    // DFS steps stack
    stack<pii> steps;

    // first: hashed position; second: depth
    pii sp(hash_pos(sx,sy), depth);

    // mark first position visited
    visited[sy][sx] = true;

    // push first position
    steps.push(sp);

    // DFS implement
    while(!steps.empty()){
        // extract first node in steps
        pii cur_node  = steps.top(); steps.pop();

        // dehash current position
        pii cur_pos   = dehash_pos(cur_node.first);

        // current depth
        int cur_depth = cur_node.second;

        // if current depth same as win condition, return game_over = true
        if(cur_depth == Succ){return true;}

        // Search 8-dir next connected piece
        for(int i=0;i<Ndir;i++){
            int next_x = cur_pos.second + nx[i];
            int next_y = cur_pos.first  + ny[i];

            // push to stack if next position has same color, not visited and
            // position is valid
            if(table[next_y][next_x] == cur_color && !visited[next_y][next_x] &&
               pos_valid(next_x, next_y)){
                pii node(hash_pos(next_x, next_y), cur_depth + 1);
                steps.push(node);
            }

            // mark as visited
            visited[next_y][next_x] = true;
        }
    }
    return false;
}

int main(){
    bool ended = false;             // Game over flag
    int y = 0, x = 0, color = 0;    // input and current color
    memset(table,0,sizeof(table));  // Table initialize
    while(!ended){
        scanf("%d,%d",&y,&x);
        table[y][x] = (color + 1);  // color 0: none, 1: black, 2: white

        // Output first answer
        pii piece = piece_number_xy(x, y);
        printf("%d:%d %d:%d\n", y, piece.first, x, piece.second);

        // Second answer
        bool over = determine_gameover(x, y, color + 1);
        if(over){
            printf("%s\n",Color[color+1].c_str());
            ended = true;
        }

        // Switch color
        color ^= 1;
    }
    return 0;
}
