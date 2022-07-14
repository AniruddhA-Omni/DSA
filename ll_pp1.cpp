#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
} *first;

void create(int A[], int n){
    int i;
    struct Node* t, *last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;
    for(i = 1; i < n; i++){
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct Node* p){
    while(p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

Node* Mid(struct Node *p){
    struct Node *t, *q;
    t = new Node;
    q = new Node;
    t = q = first;
    while(t){
        t = t->next;
        if (t) t = t->next;
        if (t) q = q->next;
    }
    return q;
}

int main(){
    int A[] = {1, 12, 30, 40, 55};
    int n = sizeof(A)/sizeof(A[0]);
    create(A, n);
    struct Node *k;
    k = Mid(first);
    cout<<k->data;
}
 