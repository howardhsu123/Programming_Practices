#include <iostream>

using namespace std;

struct QueueArray{
    double data[1024];
    uint64_t front;
    uint64_t back;

    QueueArray(){
        front = back = 0;
    }

    uint64_t size(){
        return back - front;
    }

    void push(double value){
        data[back++] = value;
    }

    double pop(){
        double value = data[front];
        data[front] = 0;
        front++;
        return value;
    }

    void output(){
        for(uint64_t i = front; i < back; i++)
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

struct QueueList{
    Node *front;
    Node *back;
    uint64_t _size;

    QueueList(){
        front = back = nullptr;
        _size = 0;
    }

    uint64_t size(){
        return _size;
    }

    void push(double value){
        Node *node = new Node;
        node->value = value;

        if(front){
            back->next = node;
            back = node;
        }
        else    
            front = back = node;
        
        _size++;
    }

    double pop(){
        double value = front -> value;
        
        Node *tmp = front;
        front = front -> next;
        delete tmp;

        _size--;
        return value;
    }

    void output(){
        for(Node *p = front; p; p = p -> next)
            cout << " " << p -> value;
        cout << endl;
    }
};

int main(void){
    QueueArray queue_array;

    for(int i = 0; i < 3; i++){
        queue_array.push(i);
    }
    return 0;
}