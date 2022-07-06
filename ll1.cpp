#include <iostream>
#include <limits.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
} *first = NULL;

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

int Count(Node* p){
    int count = 0;
    while(p != NULL){
        count++;
        p = p->next;
    }
    return count;
}

int Add(Node* p){
    int sum = 0;
    while(p != NULL){
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int Max(Node* p){
    int x = 0;
    if (p == NULL)
        return INT_MIN;
    else{
        x = Max(p->next);
        return x>p->data?x:p->data;
    }
}


int main(){
    int A[] = {1, 2, 3, 4, 5}; 
    int n = sizeof(A)/sizeof(A[0]);
    create(A, n);
    Display(first);
    return 0;
}