#include <iostream>

using namespace std;

struct StackArray{
    double data[1024];
    uint64_t back;

    StackArray(){
        back = 0;
    }

    uint64_t size(){
        return back;
    }

    void push(double value){
        data[back++] = value;
    }

    double pop(){
        return data[--back];
    }

    void output(){
        for(uint64_t i = 0; i < back; i++)
            cout << data[i] << " " ;
        cout << endl;
    }
};

struct Node{
    double value;
    Node* next;

    Node(){
        next = nullptr;
    }
};

struct StackList{
    Node* back;
    uint64_t _size;

    StackList(){    
        back -> next = nullptr;
        _size = 0;
    }

    ~StackList(){
        //上網查
    }

    uint64_t size(){
        return _size;
    }

    void push(double value){
        Node *node = new Node;
        node->value = value;

        node->next = back;
        back = node;

        _size++;
    }

    double pop(){
        double value = back -> value;

        Node *tmp = back;
        back = back -> next;
        delete tmp;

        _size--;

        return value;
    }

    void output(){
        for(Node *p = back; p; p = p -> next)
            cout << " " << p -> value;
        cout << endl;
    }
};

int main(void){
    StackArray queue_array;

    for(int i = 0; i < 3; i++){
        queue_array.push(i);
    }
    return 0;
}