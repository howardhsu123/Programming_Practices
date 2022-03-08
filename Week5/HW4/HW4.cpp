#include <iostream>
using namespace std;

struct matrix{
    uint64_t values[4];
};

matrix matrix_mod_multi(matrix A, matrix B, uint64_t R){
    matrix answer;

    answer.values[0] = ((A.values[0] * B.values[0]) % R + (A.values[1] * B.values[2]) % R) % R;
    answer.values[1] = ((A.values[0] * B.values[1]) % R + (A.values[1] * B.values[3]) % R) % R;
    answer.values[2] = ((A.values[2] * B.values[0]) % R + (A.values[3] * B.values[2]) % R) % R;
    answer.values[3] = ((A.values[2] * B.values[1]) % R + (A.values[3] * B.values[3]) % R) % R;

    return answer;
}

matrix matrix_mod_pow(matrix A, uint64_t n, uint64_t R){
    matrix tmp;

    if (n == 0){        
        tmp.values[0] = 1;
        tmp.values[1] = 0;
        tmp.values[2] = 0;
        tmp.values[3] = 1;
        return tmp;
    }
    
    if (n == 1){
        tmp = A;
        return tmp;
    }

    tmp = matrix_mod_pow(A, n/2, R);
    tmp = matrix_mod_multi(tmp, tmp, R);
    if (n%2)
        return matrix_mod_multi(tmp, A, R);
    return tmp;
}

int main(void){
    uint64_t n, R;
    cin >> n >> R;
    uint64_t init[2] {0,1};
    matrix A;
    A.values[0] = 0;
    A.values[1] = 1;
    A.values[2] = 1;
    A.values[3] = 1;

    A = matrix_mod_pow(A, n, R);
    
    cout << (init[0] * A.values[0] + init[1] * A.values[1]) % R << endl;
    return 0;
} 