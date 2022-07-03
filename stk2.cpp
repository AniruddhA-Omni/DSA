#include <iostream>
using namespace std;

// Stack using Linked List
class Node{
public:
    int data;
    Node* next;
};

class Stack{
private:
    Node *top;
public:
    Stack(){top=NULL;}
    void push(int x);
    int pop();
    void Display();
};

void Stack::push(int x){
    Node* t = new Node;
    if (t == NULL){
        cout<<"Stack is Full!\n";
    }else{
        t->data =x;
        t->next =top;
        top = t;
    }
}

int Stack::pop(){
    int x = -1;
    if (top == NULL){
        cout<<"STack is empty!\n";
    }else{
        x = top->data;
        Node* t = top;
        top = top->next;
        free(t);
    }
    return x;
}

void Stack::Display(){
    Node* p = top;
    while(p!=NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}


int main(){
    Stack stk;
    stk.push(69);
    stk.push(12);
    stk.push(77);
    stk.push(13);

    stk.Display();
    cout<<stk.pop()<<endl;
    stk.Display();
}