#include <iostream>
using namespace std;

class Queue{
private:
    int front;
    int rear;
    int size;
    int* Q;
public:
    Queue(){front=rear=-1;size=10;Q = new int[size];}
    Queue(int size){
        front=rear=-1;
        this->size=size;
        Q = new int[size];
    }
    void enqueue(int x);
    int dequeue();
    void Display();
    ~Queue(){delete []Q;}
};

int Queue::dequeue(){
    if(front==-1){
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    int x = Q[front+1];
    front++;
    return x;
}
void Queue::enqueue(int x){
    if (rear == size-1){
        cout<<"Queue is Full!"<<endl;
    }else{
        rear++;
        Q[rear] = x;
    }
}
void Queue::Display(){
    for (int i = front+1;i <= rear;i++){
        cout<<Q[i]<<" ";
    }
    cout<<endl;
}


int main(){
    Queue q(5);
    q.enqueue(69);
    q.enqueue(13);
    q.enqueue(6);
    q.enqueue(9);
    q.Display();
}