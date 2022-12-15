#include <iostream>
using namespace std;

// insert element in an array
void insert(int arr[], int n, int x, int pos, int cap){
    if(n == cap){
        return;
    }
    int idx = pos - 1;
    for(int i = n-1; i >= idx; i--){
        arr[i+1] = arr[i];
    }
    arr[idx] = x;
}

// delete element from an array
void deleteI(int arr[], int n, int pos){
    int idx = pos - 1;
    for(int i = idx; i < n-1; i++){
        arr[i] = arr[i+1];
    }
}

int main(){
    int arr[100];
    int n, x, pos;
    int cap = 100;
    cout<<"Insertion"<<endl;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    cout<<"Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    cout<<"Enter the element to be inserted: ";
    cin>>x;
    cout<<"Enter the position at which the element is to be inserted: ";
    cin>>pos;
    cout<<"The array before insertion is: ";
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    insert(arr, n, x, pos, cap);
    cout<<"The array after insertion is: ";
    for(int i = 0; i < n+1; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Deletion"<<endl;
    int arr2[100];
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    cout<<"Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin>>arr2[i];
    }
    cout<<"Enter the position at which the element is to be deleted: ";
    cin>>pos;
    cout<<"The array before deletion is: ";
    for(int i = 0; i < n; i++){
        cout<<arr2[i]<<" ";
    }
    cout<<endl;
    deleteI(arr2, n, pos);
    cout<<"The array after deletion is: ";
    for(int i = 0; i < n-1; i++){
        cout<<arr2[i]<<" ";
    }
    cout<<endl;
    return 0;
}