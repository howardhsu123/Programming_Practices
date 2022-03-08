#include <iostream> 

using namespace std;

int count(const int weight[5]){
    int answer = 0;
    int current;
    int state[500];
    for(int a = 10; a >= 0; a--){
        for(int b = a; b >= 0; b--){
            for(int c = b; c >= 0; c--){
                for(int d = c; d >= 0; d--){
                    for(int e = d; e >= 0; e--){
                        current = a*weight[0] + b*weight[1] + c*weight[2] + d*weight[3] + e*weight[4];
                        if (current >= 600 && current <= 615)
                            cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << current << endl;
                        bool flag = true;
                        for(int f = 0; f < answer; f++){  
                            if (state[f] == current){
                                flag = false;
                                break;
                            }
                        }
                        if (flag)
                            state[answer++] = current;
                    }
                }
            }
        }
    }    
    return answer;
}

int main(void){
    int weight[5] = {42,26,16,10,6};
    count(weight);
    return 0;
}