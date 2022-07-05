// Queue using linkedlist

#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

class Queue{
private:
    Node *front, *rear;
public:
    Queue(){ front = rear = NULL;}
    void Enqueue(int x);
    int Dequeue();
    void Display();
};

void Queue::Enqueue(int x){
    Node* t = new Node;
    t->data = x;
    if (rear == NULL){
        front = rear = t;
        return;
    }
    rear->next = t;
    rear = t;
}


int Queue::Dequeue(){
    int x = -1;
    if (front == NULL){
        cout<<"Queue is Empty!\n";
        return x;}
    Node* t = new Node;
    t = front;
    x = t->data;
    front = front->next;
    if (front == NULL)
        rear = NULL;
    return x;
}

void Queue::Display(){
    Node* t;
    for (t = front; t->next != NULL; t = t->next){
        cout<<t->data<<" ";
    }
    cout<<endl;
}


int main(){
    Queue q;
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Display();
    cout<<q.Dequeue()<<endl;
    //q.Display();
    q.Enqueue(69);
    q.Enqueue(13);
    //q.Display();
}
