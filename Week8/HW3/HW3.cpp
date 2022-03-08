#include <iostream>


using namespace std;
struct set{
    int amount;
    int element[30001];
    bool is_not_empty[30001];
    set();
    set U(const set &B) const;
    void input();
    void output();
    set cap(const set &B) const;
};

set::set(){
    amount = 0;
    for(int i = 0; i < 30001; i++)
        is_not_empty[i] = false;    
}

void set::input(){
    cin >> amount;
    for(int i = 0; i < amount; i++){
        cin >> element[i];
        is_not_empty[i] = true;
    }
}

set set::U(const set &B) const{
    set C;
    for(int i = 0,j = 0; i < amount || j < B.amount;){
        //cout << "HERE" << endl;
        if(element[i] == B.element[j]){
            C.element[C.amount] = element[i];
            C.is_not_empty[C.amount] = true;
            C.amount++;
            i++;
            j++;
        }
        else if((element[i] < B.element[j] || j == B.amount) && i != amount){
            C.element[C.amount] = element[i];
            //cout << "HERE" << endl;
            C.is_not_empty[C.amount] = true;
            C.amount++;
            i++;
        }
        else{
            C.element[C.amount] = B.element[j];
            C.is_not_empty[C.amount] = true;
            C.amount++;
            j++;
        }
    }
    return C;
}

void set::output(){
    for(int i = 0; i < amount; i++){
        cout << element[i];        
        if(i != amount-1)
            cout << " ";
    }
}

set set::cap(const set &B) const{
    set C;
    for(int i = 0,j = 0; i < amount || j < B.amount;){
        if(element[i] == B.element[j]){
            C.element[C.amount] = element[i];
            C.is_not_empty[C.amount] = true;
            C.amount++;
            i++;
            j++;
        }
        else if((element[i] < B.element[j] || j == B.amount) && i != amount)
            i++;
        else
            j++;
    }
    return C;
}

int main(void){
    set A;
    set B;
    A.input();
    B.input();
    cout << "union: ";
    A.U(B).output();
    cout << endl;
    cout << "intersection: ";
    A.cap(B).output();
    cout << endl;

    return 0;
}