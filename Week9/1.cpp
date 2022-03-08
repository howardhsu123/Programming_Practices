#include <iostream>
using namespace std;

struct matrix{
    int H, W;
    int R[101][101];
    void input();
    void output();
    matrix operator *(const matrix &B) const;
    matrix operator +(const matrix &B) const;
};

void matrix::input(){
    cin >> H >> W;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            char tmp;
            cin >> tmp;
            if(tmp == '-')
                R[i][j] = 1;
            else
                R[i][j] = 0;
        }
    }
}

matrix matrix::operator *(const matrix &B) const{
    matrix C;
    C.H = H-B.H+1;
    C.W = W-B.W+1;
    for(int i = 0; i < C.H; i++){
        for(int j = 0; j < C.W; j++){
            C.R[i][j] = 0;
            for(int k = 0; k < B.H; k++){
                for(int s = 0; s < B.W; s++){
                    C.R[i][j] += R[i+k][j+s] * B.R[k][s];
                }
            }
        }
    }
    return C;
}

matrix matrix::operator +(const matrix &B) const{
    matrix C;
    C.H = B.H;
    C.W = B.W;
    for(int i = 0; i < C.H; i++){
        for(int j = 0; j < C.W; j++){
            C.R[i][j] = R[i][j] * R[i][j] + B.R[i][j] * B.R[i][j];
            if(C.R[i][j] >= 8)
                C.R[i][j] = 0;
            else
                C.R[i][j] = 1;
        }
    }
    return C;
}

void matrix::output(){
    cout << H << " " << W << endl;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(R[i][j] == 1)
                cout << '-';
            else
                cout << '@';
        }
        cout << endl;
    }

}


int main(void){
    matrix C1;
    matrix C2;

    C1.H = 3;
    C1.W = 3;
    C2.H = 3;
    C2.W = 3;

    C1.R[0][0] = -1; C1.R[0][1] = -1; C1.R[0][2] = -1;
    C1.R[1][0] = 0; C1.R[1][1] = 0; C1.R[1][2] = 0;
    C1.R[2][0] = 1; C1.R[2][1] = 1; C1.R[2][2] = 1;

    C2.R[0][0] = -1; C2.R[0][1] = 0; C2.R[0][2] = 1;
    C2.R[1][0] = -1; C2.R[1][1] = 0; C2.R[1][2] = 1;
    C2.R[2][0] = -1; C2.R[2][1] = 0; C2.R[2][2] = 1;

    matrix A;

    A.input();
    
    matrix B1 = A*C1;
    matrix B2 = A*C2;
 
    (B1 + B2).output(); 

    return 0;
}