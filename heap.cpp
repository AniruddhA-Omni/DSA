#include <iostream>
using namespace std;

void Insert(int A[], int n){
    int temp = A[n], i = n;
    while(i > 1 && temp > A[i/2]){
        A[i] = A[i/2];
        i = i/2;
    }
    A[i] = temp;
}

void createHeap(int A[], int n){
    for(int i = 2; i <= n; i++){
        Insert(A, i);
    }
}

void Delete(int A[], int n){
    int i, j, x, temp;
    x = A[n];
    A[1] = A[n];
    A[n] = x;
    i = 1;
    j = i * 2;
    while(j < n - 1){
        if(A[j + 1] > A[j]){
            j = j + 1;
        }
        if(A[i] < A[j]){
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = 2 * j;
        }
        else{
            break;
        }
    }
}

void Display(int A[], int n){
    for(int i = 1; i <= n; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

int main(){
    int A[] = {0, 30, 20, 15, 5, 10, 8, 12};
    int n = sizeof(A)/sizeof(A[0])-1;
    createHeap(A, n);  
    Display(A, n);
    Delete(A, n);
    n = n-1; 
    Display(A, n);
}