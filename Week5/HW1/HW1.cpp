#include <iostream>
#include <algorithm>

using namespace std;

struct map{
    bool bits[501][501];
    int color_id[501][501];
};

void color(map &A, int H, int W, int i, int j, int id, int move[4][2]){    
    A.color_id[i][j] = id;
    for (int index = 0; index < 4; index++){
        int new_i = i + move[index][0];
        int new_j = j + move[index][1];
        if (new_i > H || new_j > W || new_i < 0 || new_j < 0)
            continue;
        else{
            if (A.color_id[new_i][new_j] != -1)
                continue;
            else if (!A.bits[new_i][new_j])
                A.color_id[new_i][new_j] = 0;
            else
                color(A, H, W, new_i, new_j, id, move);
        }
    }
    return;
}

int main(void){
    map A;
    int H,W;
    cin >> H >> W;
    int id = 0;
    int move[4][2]{
        {1,0},
        {0,1},
        {-1,0},
        {0,-1}
    };

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++)
            cin >> (A.bits[i][j]);
    }
    for(int i = 0; i < H; i++)
        fill(A.color_id[i],A.color_id[i]+W,-1);

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(A.bits[i][j] && A.color_id[i][j] == -1){
                id++;
                color(A,H,W,i,j,id,move);
            }
            else if(!A.bits[i][j])
                A.color_id[i][j] = 0;
        }
    }
/*
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++)
            cout << A.color_id[i][j] << ' ';
        cout << endl;
    }
*/
    cout << id << endl;
    return 0; 
}