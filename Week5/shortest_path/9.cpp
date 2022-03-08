#include <iostream>

using namespace std;

uint32_t shortest[30][30];
int R, C;

int drdc[4][2] = {
    {0,1},
    {0,-1},
    {1,0},
    {-1,0},
};


bool fill_shortest(int steps){
    bool updated = false;
    for(int r = 0; r < R; r++ ){
        for( int c = 0; c < C; c++){
            if(shortest[r][c] == steps - 1){
                for(int dir = 0; dir < 4; dir++){
                    int new_r = r + drdc[dir][0];
                    int new_c = c + drdc[dir][1];

                    if(new_r < 0 || R <= new_r)
                        continue;
                    if(new_c < 0 || C >= new_c)
                        continue;
                    if(shortest[new_r][new_c] != UINT32_MAX)
                        continue;
                    
                    shortest[new_r][new_c] = steps;
                    updated = true;
                }
            }
        }
    }
    return updated;
}

int main(void){
    cin >> R >> C ;

    for(int r = 0; r < R; r++ ){
        for( int c = 0; c < C; c++)
            shortest[r][c] = UINT32_MAX;
    }

    shortest[R/2][C/2] = 0;

    for(uint32_t s = 1; fill_shortest(s) ; s++);

    for(int r = 0; r < R; r++ ){
        for( int c = 0; c < C; c++)
            cout << shortest[r][c];
        cout << endl;
    }


    return 0;
}