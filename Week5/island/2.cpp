#include <iostream>

using namespace std;

struct Status{
    int map[500][500];
    int color[500][500];
    int color_id ;
};

int step[4][2] = {
{0,1},{1,0},{0,-1},{-1,0}
};

void color(int r, int c, int R, int C, Status &s){
    if(!s.map[r][c])
        return;
    if(s.color[r])
        return;
    
    s.color[r][c] = s.color_id ;
    for(int i = 0; i < 4; i++){
        int new_r = r + step[i][0];
        int new_c = c + step[i][1];

        if(new_r < 0 || R <= new_r)
            continue;
        if(new_c < 0 || C <= new_c)
            continue;
        
        color(new_r, new_c, R, C, s);
    }
}

int main(void){
    int H, W;
    cin >> H >> W;
    Status status;

    for (int h = 0; h<H; h++){
        for (int w = 0; w < W; w++){
            cin >> status.map[h][w];
            status.color[h][w] = 0;
        }
    }

    status.color_id = 1;
    for (int h = 0; h<H; h++){
        for (int w = 0; w < W; w++){
            if( status.map[h][w] == 1 && status.color[h][w] == 0){
                status.color_id ++;
                color(h, w, H, W, status);
            }
        }
    }
    for (int h = 0; h<H; h++){
        for (int w = 0; w < W; w++)
            cout << status.map[h][w];
        cout << endl;
    }

    return 0;
}