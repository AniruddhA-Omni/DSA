#include <iostream>
using namespace std;

//insertion sort
void InsertionSort(int A[], int n){
    for(int i = 1; i <n;i++){
        int j = i-1;
        int x = A[i];
        while(j>-1 && A[j] >x){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}

int main(){
    int A[] = {4,3,2,10,12,1,5,6};
    int n = sizeof(A)/sizeof(A[0]);
    InsertionSort(A, n);
    for(int i = 0; i < n; i++){
        cout << A[i] << " ";
    }
    return 0;
}