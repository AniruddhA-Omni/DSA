#include <iostream>
#include <cmath>
using namespace std;

struct Node{
    int coeff;
    int exp;
    struct Node *next;
} *p;

double Eval(int x){
    double sum = 0;
    Node *q = p;
    while(q != NULL){
        sum += q->coeff*pow(x, q->exp);
        q = q->next;
    }
}

int main(){
    Node *t = new Node;
}