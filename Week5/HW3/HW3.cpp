#include <iostream>

using namespace std;

struct map{
    char scene[31][31];
    int route[31][31];
    int start_x, start_y;
    int H, W;
};

void find_short(map &A, int x, int y, int move[8][2]){
    for(int i = 0; i < 8; i++){
        int new_x = x + move[i][0];
        int new_y = y + move[i][1];
        //cout << x << ' ' << y << endl;
        if (new_x < 0 || new_y < 0 || new_x >= A.H || new_y >= A.W)
            continue;
        if ( A.scene[new_x][new_y] == '#')
            continue;
        if ( A.scene[new_x][new_y] == 'S')
            continue;

        if ( (A.scene[new_x][new_y] == '.' || A.scene[new_x][new_y] == 'E') && (A.route[x][y] + 1) < A.route[new_x][new_y] ){
            A.route[new_x][new_y] = A.route[x][y] + 1;
            //cout << A.route[new_x][new_y] << endl;
            find_short(A, new_x, new_y, move);
        }
    }
    return;    
}

int main(void){
    map A;
    cin >> A.H >> A.W;
    int move[8][2] = {
        {0,1},
        {0,-1},
        {1,0},
        {-1,0},
        {1,1},
        {1,-1},
        {-1,1},
        {-1,-1}
    };
    
    for(int i = 0; i < A.H; i++){
        for(int j = 0; j < A.W; j++){
            A.route[i][j] = 1000000000;
            cin >> A.scene[i][j]; 
            if (A.scene[i][j] == 'S'){
                A.start_x = i;
                A.start_y = j;
                A.route[i][j] = 0;
            }
        }
    }

    find_short(A, A.start_x, A.start_y, move);

/*
    for(int i = 0; i < A.H; i++){
        for(int j = 0; j < A.W; j++){
            if (A.route[i][j] == 1000000000){
                cout << 'N' << ' ';
            }
            else
                cout << A.route[i][j] << ' ';
        }
        cout << endl;
    }
*/
    for(int i = 1; i <= A.H; i++){
        for(int j = 1; j <= A.W; j++){
            if (A.scene[i-1][j-1] == 'E')
                cout << '(' << i << ',' << j << ')' << ':'; 
            else
                continue;          

            if (A.route[i-1][j-1] == 1000000000)
                cout << "unavailable";
            else
                cout << A.route[i-1][j-1];
            cout << endl;
        }
    }

    return 0;
}