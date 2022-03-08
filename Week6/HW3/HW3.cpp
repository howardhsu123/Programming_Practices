#include <iostream> 

using namespace std;
struct list{
    int answer;
    int state[512];
};

list count(const int weight[5]){
    list A;
    A.answer = 0;
    int current;
    for(int a = 10; a >= 0; a--){
        for(int b = a; b >= 0; b--){
            for(int c = b; c >= 0; c--){
                for(int d = c; d >= 0; d--){
                    for(int e = d; e >= 0; e--){
                        current = a*weight[0] + b*weight[1] + c*weight[2] + d*weight[3] + e*weight[4];
                        bool flag = true;
                        for(int f = 0; f < A.answer; f++){  
                            if (A.state[f] == current){
                                flag = false;
                                break;
                            }
                        }
                        if (flag){
                            A.state[A.answer++] = current;
                            //cout << current << endl; 
                        }
                    }
                }
            }
        }
    } 
    return A;
}

int main(void){
    int weight[5] = {42,26,16,10,6};
    list A = count(weight);
    int n;
    while(cin >> n){
        bool flag = true;
        for (int i = 0; i < A.answer ; i++){
            if(n == A.state[i]){
                cout << n << ":" << ' ' << "VALID" << endl;
                flag = false;
                break;
            }
        }
        if (flag){
            cout << n << ":" << ' ' << "INVALID" << endl;
        }
    }
    return 0;
}