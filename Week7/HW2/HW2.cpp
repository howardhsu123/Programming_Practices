#include <iostream>
using namespace std;

int main(void){
    char A[251];
    int count = 0;
    bool flag;
    while(cin >> A){
        count = 0;
        while(A[count])
            count++;
        flag = true;
        for(int i = 0; (i < count) && flag; i++){
            if (*(A+i) != *(A + count - i - 1)){
                cout << "NO" << endl;
                flag = false;
            }
        }
        if(flag)
            cout << "YES" << endl;
        
    }

    return 0;
}