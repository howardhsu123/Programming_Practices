#include <iostream>
#include <algorithm>

using namespace std;

int data[100];

int main(void){
    int N;

    for(N = 0; cin >> data[N] ; N++);
    sort(data, data+10);
    for(int i = 0; i < N; i++){
        if(i)
            cout << ", " << data[i];
        else
            cout << data[i];
    }
    cout << endl;

    return 0;
}