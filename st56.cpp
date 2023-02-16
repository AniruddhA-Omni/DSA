#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct node
{
 int info;
 struct node *ptr;
}*top,*top1,*temp;

class stack{
private:
    int count;
public:
    int topelement();
    void push(int data);
    void pop();
    void empty();
    void display();
    void stack_count();
    void create();
    ~stack(){
        top1 = top;
        while (top1 != NULL){
            top1 = top->ptr;
            delete top;
            top = top1;
            top1 = top1->ptr;
        }
        delete top1;
        top = NULL;
        printf("\n All stack elements destroyed");
        count = 0;
    }
};


/* Create empty stack */
void stack::create(){
    top = NULL;
    count = 0;
}
/* Count stack elements */
void stack::stack_count(){
    printf("\n No. of elements in stack : %d", count);
}
/* Push data into stack */
void stack::push(int data){
    if (top == NULL){
        top = new node;
        top->ptr = NULL;
        top->info = data;
    }
    else{
        temp = new node;
        temp->ptr = top;
        temp->info = data;
        top = temp;
    }
    count++;
}
/* Display stack elements */
void stack::display(){
    top1 = top;
    if (top1 == NULL){
        printf("Stack is empty");
        return;
    }
    while (top1 != NULL){
        printf("%d ", top1->info);
        top1 = top1->ptr;
    }
}
/* Pop Operation on stack */
void stack::pop(){
    top1 = top;
    if (top1 == NULL){
        printf("\n Error : Trying to pop from empty stack");
        return;
    }
    else{
    top1 = top1->ptr;
    printf("\n Popped value : %d", top->info);
    delete top;
    top = top1;
    count--;
    }
}

/* Return top element */
int stack::topelement(){
    return(top->info);
}
/* Check if stack is empty or not */
void stack::empty(){
    if (top == NULL)
        printf("\n Stack is empty");
    else
        printf("\n Stack is not empty with %d elements", count);
}

int main(){
    int no, ch, e;
    stack s;
    printf("\n 1 - Push");
    printf("\n 2 - Pop");
    printf("\n 3 - Top");
    printf("\n 4 - Empty");
    printf("\n 5 - Exit");
    printf("\n 6 - Dipslay");
    printf("\n 7 - Stack Count");
    printf("\n 8 - Destroy stack");
    s.create();
    while (1){
        printf("\n Enter choice : ");
        scanf("%d", &ch);
        switch (ch){
        case 1:
            printf("Enter data : ");
            scanf("%d", &no);
            s.push(no);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            if (top == NULL)
                printf("No elements in stack");
            else{
                e = s.topelement();
                printf("\n Top element : %d", e);
            }
            break;
        case 4:
            s.empty();
            break;
        case 5:
            exit(0);
        case 6:
            s.display();
        break;
            case 7:
            s.stack_count();
            break;
        case 8:
            s.~stack();
            break;
        default :
            printf(" Wrong choice, Please enter correct choice ");
            break;
        }
    }
    return 0;
}