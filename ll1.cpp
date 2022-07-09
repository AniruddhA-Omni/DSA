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

void Insert(struct Node* p, int index,int x){
    if (index < 0 || index >Count(p)) return;
    struct Node* t = new Node;
    t->data = x;
    t->next = NULL;
    if (index == 0){
        t->next = first;
        first = t;
    }
    else{
        for(int i = 0; i < index-1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

void SortedInsert(struct Node* p, int x){
    struct Node* t, *q = NULL;
    t = new Node;
    t->data = x;
    t->next = NULL;
    if(first == NULL){
        first = t;
    }else{
        while(p && p->data < x){
            q = p;
            p = p->next;
        }
        if(p == first){
            t->next = first;
            first = t;
        }else{
            t->next = q->next;
            q->next = t;
        }
    }
}

 



int main(){
    int A[] = {1, 2, 3, 4, 5}; 
    int n = sizeof(A)/sizeof(A[0]);
    create(A, n);
    Display(first);
    Insert(first, 2, 10);
    Display(first);
    return 0;
}