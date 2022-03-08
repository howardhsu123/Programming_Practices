#include <iostream>

using namespace std;

int main(void){
    int data[9];
    int answer;
    while (cin >> data[0]){
        answer = 0;
        for (int i = 1; i < 9; i++){
            cin >> data[i];
            answer += (9-i) * data[i];
        }
        answer += data[0]/10 + 9*(data[0]%10);
        answer %= 10;
        answer = (10 - answer) % 10;

        cout << data[0] << "-";
        for (int i = 1; i < 9; i++)
            cout << data[i];
        cout << answer << endl;
    }
    return 0;
}