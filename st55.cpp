#include <iostream>
using namespace std;

template <class T>
// stack using cpp
class Stack{
private:
    T *st;
    int top;
    int size;
public:
    Stack(){
        size = 10;
        top =-1;
        st = new T[size];
    }
    Stack(int n){
        size = n;
        top = -1;
        st = new T[size];
    }

    void push(T x);
    T pop();
    T peek(int index);
    int stacktop();
    int isEmpty();
    int isFull();
    void Display();

    ~Stack(){
        delete []st;
    }
};

template <class T>
void Stack<T>::push(T x){
    if (isFull())
        cout<<"Stack Overflow!\n";
    else{
        top++;
        st[top] = x;
    }
}

template <class T>
T Stack<T>::pop(){
    T x = -1;
    if(isEmpty())
        cout<<"Stack Underflow!\n";
    else{
        x = st[top];
        top--;
    }
    return x;
}
template <class T>
T Stack<T>::peek(int index){
    T x = -1;
    if (top - index +1 < 0)
        cout<<"Invalid Index!";
    else{
        x = st[top - index + 1];
    }
    return x;
}

template <class T>
int Stack<T>::stacktop(){
    if(isEmpty()) return -1;
    return st[top];
}

template <class T>
int Stack<T>::isEmpty(){
    return top == -1;
}

template <class T>
int Stack<T>::isFull(){
    return top == size-1;
}

template <class T>
void Stack<T>::Display(){
    for(int i = 0; i< size; i++){
        cout<<st[i]<<" ";
    }
    cout<<endl;
}


int main(){
    Stack<char> stk(5);
    stk.push('a');
    stk.push('b');
    stk.push('c');
    stk.push('d');
    stk.push('e');
    stk.Display();
    Stack<char> stk2(5);
    for(int i =0; i <5; i++){
        stk2.push(stk.pop());
    }
    stk2.Display();
    return 0;
}