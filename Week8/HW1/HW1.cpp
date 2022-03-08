#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool is_operator(const char &ch){
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return true;
    return false;
}

int operate(const int &a, const int &b, const char &ch){
    if(ch == '+')
        return a+b;
    if(ch == '-')
        return a-b;
    if(ch == '*')
        return a*b;
    if(ch == '/')
        return a/b;
    return 0;
}

int solve(string postfix){
    int a, b;
    stack <int> buffer;
    string::iterator it;
    for(it = postfix.begin(); it != postfix.end(); it++){
        if(is_operator(*it)){
            b = buffer.top();
            buffer.pop();
            a = buffer.top();
            buffer.pop();
            buffer.push(operate(a,b,*it));
        }
        else
            buffer.push((int)(*it - '0'));
    }
    return buffer.top();
}

int main(void){
    string tmp;
    while(cin >> tmp)
        cout << solve(tmp) << endl;

    return 0;
}
