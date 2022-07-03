#include <iostream>
#include <string>
using namespace std;

class Node{
public:
    char data;
    Node* next;
};

class Stack{
private:
    Node *top;
public:
    Stack(){top=NULL;}
    void push(char x);
    char pop();
    void Display();
    int isBalanced(string exp);
    string InToPost(string infix);
    int isOperand(char x);
    int pre(char x);
    int Eval(string postfix);
};

void Stack::push(char x){
    Node* t = new Node;
    if (t == NULL){
        cout<<"Stack is Full!\n";
    }else{
        t->data =x;
        t->next =top;
        top = t;
    }
}

char Stack::pop(){
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

int Stack::isBalanced(string exp)
{
    int i;
    for(auto i: exp){
    if(exp[i]=='(')
        push(exp[i]);
    else if(exp[i]==')'){
    if(top==NULL)
        return 0;
        pop();
    }
    }
    if(top==NULL)
        return 1;
    else
        return 0;
}

string Stack::InToPost(string infix){
    int i = 0, j = 0;
    string* postfix;
    long len = infix.length();
    postfix = new string[len+2];
    while(infix[i] != '\0'){
        if(isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else{
            if(pre(infix[i])>pre(top->data))
                push(infix[i++]);
            else{
                postfix[j++]=pop();
            }
        }
    }
    while(top != NULL){
        postfix[j++] = pop();
        postfix[j] = '\0';
    }
    return *postfix;
}

int Stack::isOperand(char x){
    if(x == '+' || x == '-' || x == '*' || x== '/')
        return 0;
    else
        return 1;
}

int Stack::pre(char x){
    if(x == '+' || x == '-')
    return 1;
    else if (x == '*' || x == '/'){
        return 2;
    }
    return 0;
}


int Stack::Eval(string postfix){
    int i=0;
    int x1,x2,r=0 ;
    for(auto i : postfix){
        if(isOperand(postfix[i])){
        push(postfix[i]-'0');
        }else{
        x2 = pop();
        x1 = pop();
        switch(postfix[i]){
            case '+':r=x1+x2; break;
            case '-':r=x1-x2; break;
            case '*':r=x1*x2; break;
            case '/':r=x1/x2; break;
        }
        push(r);
        }
    }
    return top->data;
}


int main(){
    string exp="234*+82/-";
    Stack st;
    cout<<st.Eval(exp);
}