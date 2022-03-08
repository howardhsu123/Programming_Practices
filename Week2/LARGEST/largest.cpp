#include <bits/stdc++.h>

using namespace std;

int main(void){
    int64_t value;
    int64_t answer = INT64_MIN;

    while(cin >> value){
        //cout << "* "<< value << endl;
        if (value > answer){
            answer = value;
        }
    }
    cout << answer << endl;

    return 0 ;
}