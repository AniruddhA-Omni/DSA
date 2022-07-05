#include <iostream>
using namespace std;

class CQueue{
private:
    int front;
    int rear;
    int size;
    int* Q;
public:
    CQueue(){front=rear=0;size=10;Q = new int[size];}
    CQueue(int size){
        front=rear=0;
        this->size=size;
        Q = new int[size];
    }
    void enqueue(int x);
    int dequeue();
    void Display();
    ~CQueue(){delete []Q;}
};

int CQueue::dequeue(){
    if(front == rear){
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    front =(front+1) % size;
    int x = Q[front];
    return x;
}
void CQueue::enqueue(int x){
    if ((rear+1)%size == front){
        cout<<"Queue is Full!"<<endl;
    }else{
        rear = (rear + 1)%size;
        Q[rear] = x;
    }
}
void CQueue::Display(){
    int i = front +1;
    do{
        cout<<Q[i]<<" ";
        i = (i+1)%size;
    }while(i != (rear+1)%size);

    cout<<endl;
}


int main(){
    CQueue q(5);
    q.enqueue(69);
    q.enqueue(13);
    q.enqueue(6);
    q.enqueue(9);
    q.Display();
} 

