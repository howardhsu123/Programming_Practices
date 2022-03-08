#include <iostream>
#include <algorithm>

using namespace std;

struct student{
    int sum;
    int scores[4];
};

bool cmp(student A, student B){
    return (A.sum > B.sum) || (A.sum == B.sum) && (A.scores[0] < B.scores[0])
                           || (A.sum == B.sum) && (A.scores[0] == B.scores[0]) && (A.scores[1] < B.scores[1])
                           || (A.sum == B.sum) && (A.scores[0] == B.scores[0]) && (A.scores[1] == B.scores[1]) && (A.scores[2] < B.scores[2]);
}

int main(void){
    int n ;
    cin >> n;
    student students[500];
    for (int i = 0; i < n; i++){
        students[i].sum = 0;
        for (int j = 0; j < 4; j++){
            cin >> students[i].scores[j];
            students[i].sum += students[i].scores[j];
        }
    }
    sort (students, students+n, cmp);
    for (int i = 0; i < n; i++){
        cout << students[i].sum;
        for (int j = 0; j < 4; j++)
            cout << ' ' << students[i].scores[j];
        cout << endl;
    }
    return 0;
}