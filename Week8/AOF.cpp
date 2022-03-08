#include <iostream>

using namespace std;

struct AOF_Array{
    double data[1024];
    uint64_t _size;
    AOF_Array(){
        _size = 0;
    }

    void append(double value){
        data[_size++] = value;
    }

    uint64_t size(){
        return _size;
    }

    void output(){
        for(uint64_t i = 0; i < _size; i++)
            cout << ' ' << data[i];
        cout << endl;
    }
};

struct Node{
    double value;
    Node *next;

    Node(){
        next = nullptr;
    }
};

struct AOF_List{
    Node *head;
    Node *tail;
    uint64_t _size;
    AOF_Array(){
        head = nullptr;
        tail = nullptr;
        _size = 0;
    }

    void append(double value){
        Node *node = new Node;
        node -> value = value;
        
        if(tail){
            tail -> next = node;
            tail = node;
        }
        else
            head = tail = node;
    
        _size++;
    }

    uint64_t size(){
        return _size;
    }

    void output(){
        for(Node* p = head; p; p = p -> next)
            cout << " " << p -> value;
        cout << endl;
    }
}

int main(void){
    AOF_Array aof_arr;

    for(int i = 0; i < aof_arr.size(); i++){
        aof_arr.append(i);
        aof_arr.output();
    }
}