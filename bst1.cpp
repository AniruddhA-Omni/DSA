#include <iostream>
using namespace std;

struct Node{
    /* data */
    struct Node *lchild;
    int data;
     struct Node *rchild;
}*root=NULL;

void Insert(int key){
    struct Node* t =root;
    struct Node *r, *p;
    if (root == NULL){
        p = new Node;
        p->data = key;
        p->lchild = p->rchild =NULL;
        root=p;
        return;
    }
    while(t!= NULL){
        r = t;
        if (key<t->data)
            t = t->lchild;
        else if (key > t->data)
            t = t->rchild;
        else
            return;
    }
    p = new Node;
    p->data = key;
    p->lchild = p->rchild =NULL;
    if (key < r->data) r->lchild = p;
    else r->rchild = p;
}


void Inorder(struct Node* p){
    if (p){
        Inorder(p->lchild);
        cout<<p->data<<" ";
        Inorder(p->rchild);
    }
}

struct Node* Search(int key){
    struct Node *t =root;
    while(t!=NULL){
        if (key == t->data)
            return t;
        else if (key < t->data)
            t = t->lchild;
        else
            t =t->rchild;
    }
    return NULL;
} 

int main(){
    struct Node* temp;
    Insert(10);
    Insert(13);
    Insert(77);
    Insert(20);
    Insert(9);
    Insert(5);
    Insert(12);
    Inorder(root);
    temp = Search(20);
    cout<<endl;
    if (temp != NULL){
        cout<<temp->data;
    }else{
        cout<<"Not found";
    }
}