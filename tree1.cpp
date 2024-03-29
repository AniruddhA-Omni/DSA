#include <iostream>
using namespace std;

///////////////////////////
class Node{
public:
    Node *lchild;
    int data;
    Node *rchild;
};
class Queue{
private:
    int front;
    int rear;
    int size;
    Node **Q;
public:
    Queue(){front=rear=-1;size=10;Q = new Node*[size];}
    Queue(int size){
        front=rear=-1;
        this->size=size;
        Q = new Node*[size];
    }
    void enqueue(Node *x);
    bool isEmpty();
    Node *dequeue();
    void Display();
    ~Queue(){delete []Q;}
};

Node* Queue::dequeue(){
    Node *x = NULL;
    if(front==rear){
        cout<<"Queue is empty"<<endl;
    }else{
    x = Q[front+1];
    front++;}
    return x;
}
void Queue::enqueue(Node* x){
    if (rear == size-1){
        cout<<"Queue is Full!"<<endl;
    }else{
        rear++;
        Q[rear] = x;
    }
}
void Queue::Display(){
    for (int i = front+1;i <= rear;i++){
        cout<<Q[i]<<" ";
    }
    cout<<endl;
}
bool Queue::isEmpty(){
    if (front == rear){
        return true;
    }
    return false;
}
/////////////////////////

class Tree{
    Node *root;
public:
    Tree(){root = NULL;}
    void CreateTree();
    void Preorder(){Preorder(root);}
    void Preorder(Node *p);
    void Postorder(){Postorder(root);}
    void Postorder(Node *p);
    void Inorder(){Inorder(root);}
    void Inorder(Node *p);
    void Levelorder(){Levelorder(root);}
    void Levelorder(Node *p);
    int Heigth(){return Heigth(root);}
    int Heigth(Node *root);
};

void Tree::CreateTree(){
    Node *p, *t;
    int x;
    Queue q(100);
    cout<<"Enter root value: "; cin>>x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);
    while(!q.isEmpty()){
        p = q.dequeue();
        cout<<"Enter Left child of "<<p->data<<": ";
        cin>>x;
        if(x != -1){
            t = new Node;
            t->data =x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }
        cout<<"Enter Right child of "<<p->data<<": ";
        cin>> x;
        if(x != -1){
            t = new Node;
            t->data =x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void Tree::Preorder(struct Node* p){
    if (p){
        cout<<p->data<<" ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::Inorder(struct Node *p){
    if(p){
        Inorder(p->lchild);
        cout<<p->data<<" ";
        Inorder(p->rchild);
    }
}

void Tree::Postorder(struct Node *p){
    if(p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout<<p->data<<" ";
    }
}

void Tree::Levelorder(struct Node *root){
    Queue q(100);
    cout<<root->data<<" ";
    q.enqueue(root);
    while(!q.isEmpty()){
        root=q.dequeue();
        if(root->lchild){
            cout<<root->lchild->data<<" ";
            q.enqueue(root->lchild);
        }
        if(root->rchild){
            cout<<root->rchild->data<<" ";
            q.enqueue(root->rchild);
        }
    }
}

int Tree::Heigth(struct Node *root){
    int x=0,y=0;
    if(root==0){
        return 0;}
    x=Heigth(root->lchild);
    y=Heigth(root->rchild);
    if(x>y){
     return x+1;
    }else{
    return y+1;}
}

int count(Node *p){
    int x,y;
    if (p != NULL){
        x = count(p->lchild);
        y = count(p->rchild);
        if (p->lchild && p->rchild) return x+y+1;
        return x+y;
    }
    return  0;
}


int main(){
    Tree t;
    t.CreateTree();
    cout<<"Preorder ";
    t.Preorder();
    cout<<endl;
    cout<<"Inorder ";
    t.Inorder();
    cout<<endl;
    cout<<"Postorder ";
    t.Postorder();
    cout<<endl;
}