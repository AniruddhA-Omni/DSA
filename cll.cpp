#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
} *head;

void Create(int A[], int n){
    int i;
    Node *t, *last;
    head = new Node;
    head->data = A[0];
    head->next = head;
    last = head;
    for(i = 1;i<n;i++){
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last =t;
    }
}


void Display(Node *p){
    head = p;
    do{
        cout<<p->data<<" ";
        p = p->next;
    } while (p != head);
    cout<<endl;
}

int Length(Node* p){
    int len = 0;
    do{
        len++;
        p = p->next;
    }while(p != head);
    return len;
}


void Insert(Node* p, int index, int x){
    Node* t;
    int i;
    if (index<0 || index > Length(head)) return;
    if (index == 0){
        t = new Node;
         t->data = x;
         if (head == NULL){
            head = t;
            head->next = head;
         }else{
            while(p->next != head) p = p->next;
            p->next =t;
            t->next =head;
            head = t;
         }
    }else{
        for(i = 0; i<index;i++){
            p = p->next;
        }
            t = new Node;
            t->data = x;
            t->next = p->next;
            head = t;
        
    }
}
// bugs in insert

int Delete(Node* p, int index){
    Node* q;
    int i, x;
    if (index<0 || index > Length(head)) return -1;
    if (index == 1){
        while(p->next != head) p = p->next;
        x = head->data;
        if (head == p){
            delete head;
            head == NULL;
        }else{
            p->next = head->next;
            delete head;
            head = p->next;
        }
    }else{
        for(i = 0; i< index-2; i++){
            p = p->next;
        }
        q = p->next;
        p->next= q->next;
        x = q->data;
        delete q;
    }
    return x;
}

int main(){
    int A[] = {1,2,3,4,5,6};
    Create(A,6);
    Display(head);
    // Insert(head,2,77);
    // Display(head);
    Delete(head,1);
    Display(head);
}