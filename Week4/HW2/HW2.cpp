#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef struct cat{
    string name;
    string prof;
    int level;
    int age;
}cat;

void identify(cat &A){
    if (A.prof == "elder")
        A.level = 0;
    if (A.prof == "nursy")
        A.level = 1;
    if (A.prof == "kit")
        A.level = 2;
    if (A.prof == "warrior")
        A.level = 3;
    if (A.prof == "apprentice")
        A.level = 4;
    if (A.prof == "medicent")
        A.level = 5;
    if (A.prof == "deputy")
        A.level = 6;
    if (A.prof == "leader")
        A.level = 7;
}

bool cmp(cat A, cat B){
    if (A.level < B.level)
        return true;
    else if(A.level > B.level)
        return false;
    else{
        if (A.level == 4){
            if (A.age < B.age)
                return true;
            else if (A.age > B.age)
                return false;
        }
        else{
            if (A.age > B.age)
                return true;
            else if (A.age < B.age)
                return false;
        }
        if (A.age == B.age){
            for(int i = 0; A.name[i] != ' '; i++){
                if (A.name[i] < B.name[i])
                    return true;
                else if (A.name[i] > B.name[i])
                    return false;
            }
        }
    }
    return true;
}

int main(void){
    int cats, foods;
    cin >> cats >> foods;
    cat A[10001];
    char tmp;
    for(int c = 0; c < cats; c++){
        cin >> A[c].name;
        cin >> A[c].prof;
        cin >> A[c].age;
        identify(A[c]);
    }
    sort(A,A+cats,cmp);
    for(int c = 0; c < foods; c++)
        cout << A[c].name << endl;
    return 0;
}