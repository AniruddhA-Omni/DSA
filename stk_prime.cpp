#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

class Stack{
private:
    Node *top;
public:
    Stack(){top=NULL;}
    void push(int x);
    void Display();
    bool isPrime(int n);
    void deletePrimeNodes();
    void deleteNode(Node* del);
};

void Stack::push(int x){
    Node* t = new Node;
    if (t == NULL){
        cout<<"Stack is Full!\n";
    }else{
        t->data =x;
        t->next =top;
        top = t;
    }
}

void Stack::Display(){
    Node* p = top;
    while(p!=NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

bool Stack::isPrime(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
 
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
 
    return true;
}

void Stack::deleteNode(Node* del){
    Node* temp = top;
    // base case
    if (top == NULL || del == NULL)
        return;
    if(top == del){
        top = del->next;
        return;}
    while(temp->next != del){
        temp = temp->next;
    }
    temp->next = del->next;
    delete del;
    return;
}

// function to delete all prime nodes from the singly linked list
void Stack::deletePrimeNodes()
{
	Node* ptr = top;
	Node* next;

	while (ptr != NULL) {
		next = ptr->next;
		if (isPrime(ptr->data))
			deleteNode(ptr);
		ptr = next;
	}
}


// Driver program
int main(){
	// start with the empty list
    Stack stk;
	// create the linked list
    stk.push(17);
    stk.push(6);
    stk.push(7);
    stk.push(16);
    stk.push(15);
    stk.push(3);
    stk.push(8);
    stk.push(2);
    stk.push(4);

	cout << "Original List: ";
    stk.Display();
	stk.deletePrimeNodes();
    cout<<"After deleting all prime nodes from the list:";
	cout << "\nModified List: ";
    stk.Display();
}
