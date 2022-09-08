#include <iostream>
using namespace std;

struct Node{
    Node* rchild;
    Node* lchild;
    int data;
}*root = NULL;
struct Stack{
    Node* top;
};

void createPre(int pre[], int n){
     struct Node *p, *t;
     struct Stack stk;
     int i = 0;
     root = new Node;
     root->data = pre[i++];
     root->lchild = root->rchild = NULL;
     p =root;
     while (i < n){
        if (pre[i] < p->data){
            t = new Node;
            t->data = pre[i];
            t->lchild = t->rchild =NULL;
            p->lchild =t;
            // push(stk, p);
            p = t;
        }else{
            if (pre[i]> p->data && pre[i]<stackTop(stk)->data){
                t =new Node;
                t->data = pre[i++];
                t->lchild =t->rchild =NULL;
                p->rchild = t;
                p =t;
            }else{
                p =pop(&stk);
            }
        }
     }
}


int main(){

}