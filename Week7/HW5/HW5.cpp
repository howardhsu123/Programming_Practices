#include <iostream>

using namespace std;

int main(void){
    int A[10000];
    int B[10000];
    int i,j,k;
    cin >> i >> j >> k;
    for(int x = 0; x < i; x++){
        for(int y = 0; y < j; y++){
            cin >> *(A+x*j+y);
        }
    }
    for(int x = 0; x < j; x++){
        for(int y = 0; y < k; y++){
            cin >> *(B+x*k+y);
        }
    }
    for(int ans_x = 0; ans_x < i; ans_x++){
        for(int ans_y = 0; ans_y < k; ans_y++){
            int to_print = 0;
            for(int t = 0; t < j; t++)
                to_print += *(A+ans_x*j+t) * *(B+t*k+ans_y);
            cout << to_print;
            if(ans_y != k-1)
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}