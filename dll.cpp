#include <iostream>
using  namespace std;

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
} *first = NULL;

void Create(int A[], int n){
    struct Node* t, *last;

    first = new Node;
    first->data = A[0];
    first->prev = first->next = NULL;
    last =first;
    
    for(int i =1;i<n;i++){
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void Display(struct Node* p){
    while(p){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

int Length(struct Node *p){
    int len = 0;
    while(p){
        len++;
        p = p->next;
    }
    return len;
}

void Insert(struct Node* p, int index, int x){
    struct Node* t;
    int i;
    t = new Node;
    if (index < 0 || index > Length(p)) return;
    if (index == 0){
        t->data = x;
        t->next = first;
        first->prev = t;
        first = t;
    }else{
        for(i = 0; i <index -1;i++){
            p =p->next;
        }
        t->data = x;
        t->prev = p;
        t->next = p->next;
        if (p->next) p->next->prev = t;
        p->next = t;
    }
}

int main(){
    int A[] = {10,20,30,45,55,65};
    Create(A,6);
    Display(first);
    Insert(first,4,69);
    Display(first);
}