#include <iostream>
using namespace std;

bool Input(char A[9]){
    char empty;
    if (cin >> A[0]){
        for(int i = 1; i < 9; i++)
            cin >> A[i];
        return true;
    }
    return false;
}

bool IsOwin(char A[9]){
    bool answer = false;
    for (int i = 0; i < 9; i+=3)
        answer |= (A[i] == 'O') && (A[i+1] == 'O') && (A[i+2] == 'O');
    for (int i = 0; i < 3; i++)
        answer |= (A[i] == 'O') && (A[i+3] == 'O') && (A[i+6] == 'O');
    answer |= (A[0] == 'O') && (A[4] == 'O') && (A[8] == 'O');
    answer |= (A[2] == 'O') && (A[4] == 'O') && (A[6] == 'O');
    return answer;
}

bool IsXwin(char A[9]){
    bool answer = false;
    for (int i = 0; i < 9; i+=3)
        answer |= (A[i] == 'X') && (A[i+1] == 'X') && (A[i+2] == 'X');
    for (int i = 0; i < 3; i++)
        answer |= (A[i] == 'X') && (A[i+3] == 'X') && (A[i+6] == 'X');
    answer |= (A[0] == 'X') && (A[4] == 'X') && (A[8] == 'X');
    answer |= (A[2] == 'X') && (A[4] == 'X') && (A[6] == 'X');
    return answer;
}

bool IsFull(char A[9]){
    for(int i = 0; i < 9; i++){
        if (A[i] == '.')
            return false;
    }
    return true;
}

int Steps(char A[9]){
    int count = 0;
    for (int i = 0; i < 9; i++){
        if(A[i] == 'X')
            count++;
        if(A[i] == 'O')
            count--;
    }
    return count;
}

bool NoCheat(char A[9]){
    if (Steps(A) > 1 || Steps(A) < 0)
        return false;
    if (IsOwin(A) && IsXwin(A))
        return false;
    if (IsOwin(A) && (Steps(A) == 1))
        return false;
    if (IsXwin(A) && (Steps(A) == 0))
        return false;
    return true;
}

int main(void){
    char A[9];
    while(Input(A)){
        if(NoCheat(A)){
            if(IsXwin(A))
                cout << "X win";
            else if(IsOwin(A))
                cout << "O win";
            else if(IsFull(A))
                cout << "Tie";
            else
                cout << "Not yet";
        }
        else   
            cout << "Cheating!";
        cout << endl;
    }
    return 0;
}