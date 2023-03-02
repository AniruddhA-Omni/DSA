#include <iostream>
using namespace std;

// partition exchange sort
void QuickSort(int A[], int l, int h){
    int i = l, j = h;
    int pivot = A[(l+h)/2];
    do{
        while(A[i] < pivot) i++;
        while(A[j] > pivot) j--;
        if (i <= j){
            A[i] = A[i] ^ A[j];
            A[j] = A[i] ^ A[j];
            A[i] = A[i] ^ A[j];
            i++;
            j--;
        }
    }while(i <= j);
    if (l < j) QuickSort(A, l, j);
    if (i < h) QuickSort(A, i, h);
}

int main(){
    int A[] = {3,7,9,10,6,5,12,4,11,2};
    int n = sizeof(A)/sizeof(A[0]);
    QuickSort(A, 0, n-1);
    for(int i = 0; i < n; i++){
        cout << A[i] << " ";
    }
    return 0;
}