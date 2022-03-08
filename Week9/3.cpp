#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int N, M;

    cin >> N >> M;
    float student[20];
    for(int i = 0; i < N; i++)
        cin >> student[i];
    
    sort(student, student+N);

    float tmp;
    for(int j = 0; j < M; j++){    
        int a = 0; 
        cin >> tmp;
        for(int i = 0; i < N; i++){
            if(student[i] == tmp){
                while(student[i] == tmp && i != N){
                    i++;
                    a++;
                }
                a--;
                break;
            }
            a++;
        }
        cout << (a*100) / N << endl;
    }
    return 0;
}