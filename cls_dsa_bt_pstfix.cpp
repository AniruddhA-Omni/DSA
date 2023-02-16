#include <iostream>
using namespace std;

// post-fix using binary expression tree
class Node {
public:
  char data;
  Node *left;
  Node *right;
  Node(char data) {
    this->data = data;
    left = NULL;
    right = NULL;
  }
};

class Stack {
private:
  Node *top;
public:
    Stack() {
        top = NULL;
    }
    void push(Node *node) {
        if (top == NULL) {
        top = node;
        } else {
        node->left = top;
        top = node;
        }
    }
    Node *pop() {
        if (top == NULL) {
        return NULL;
        } else {
        Node *temp = top;
        top = top->left;
        return temp;
        }
    }
    Node *peek() {
        return top;
    }
    bool isEmpty() {
        return top == NULL;
    }
    };

int main(){
        Stack stack;
        string expression;
        cout << "Enter expression: ";
        cin >> expression;
        for (int i = 0; i < expression.length(); i++) {
            char ch = expression[i];
            if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
                Node *node = new Node(ch);
                Node *right = stack.pop();
                Node *left = stack.pop();
                node->right = right;
                node->left = left;
                stack.push(node);
            } else {
                Node *node = new Node(ch);
                stack.push(node);
            }
        }
    }