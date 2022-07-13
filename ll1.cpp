#include <iostream>
#include <limits.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

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
void create2(int A[], int n){
    int i;
    struct Node* t, *last;
    second = new Node;
    second->data = A[0];
    second->next = NULL;
    last = second;
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

int Delete(struct Node* p, int index){
    struct Node* q;
    int x = -1;
    if (index < 0 || index > Count(p)) return x;
    if (index == 1){
        q =first;
        x = first->data;
        first = first->next;
        delete q;
        return x;
    }
    else{
        for(int i = 0; i < index-1; i++)
            p = p->next;
        q = p->next;
        x = q->data;
        p->next = q->next;
        delete q;
        return x;
    }
}

int isSorted(struct Node* p){
    int x = -652656;
    while(p!= NULL){
        if(p->data > x)
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1; 
}

void RemoveDup(struct Node* p){
    struct Node* q= p->next;
    while(q!=NULL){
        if (p->data != q->data){
            p =q;
            q = q->next;
        }else{
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

void Reverse(struct Node* p){
    p = first;
    struct Node *q, *r;
    while(p != NULL){
        r = q;
        q = p;
        p = p->next;
        q->next = r; 
    }
    first = q;
}

void Concat(struct Node *p, struct Node *q){
    third = p;
     while(p->next != NULL){
        p = p->next;
     }
     p->next = q;
}

void Merge(struct Node *p, struct Node *q){
    struct Node *last;
    if (p->data < q->data){
        third = last = p;
        p = p->next;
        third->next = NULL;
    }else{
        third = last = q;
        q = q->next;
        third->next = NULL;
    }

    while( p && q){
        if (p->data < q->data){
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }else{
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p) last->next = p;
    if (q) last->next = q;
}

int main(){
    int A[] = {1, 12, 30, 40, 55};
    int B[] = {10,20,35,45,50}; 
    int n = sizeof(A)/sizeof(A[0]);
    create(A, n);
    Display(first);
    // Insert(first, 2, 10);
    // Display(first);
    create2(B,5);
    Display(second);

    Merge(first, second);
    Display(third);
    return 0;
}