#include <iostream>
#include <array>
using namespace std;
/*
int main(){
    array<int, 10> arr = {1, 2, 3, 4, 5};
    for(auto i : arr){
        cout << i << " ";
    }
    cout << endl;
    cout << arr.data() << endl;
    cout << arr.size() << endl;
    cout << arr.max_size() << endl;
    cout << arr.empty() << endl;
    cout << arr.front() << endl;  
    arr.front() = 10;
    for(auto i : arr){
        cout << i << " ";
    }
     cout << arr.back() << endl;
    arr.fill(10);
    for(auto i: arr){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
*/
struct Array{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr){
    int i;
    cout<< "Elements of array are: ";
    for (i =0; i<arr.length;i++){
        cout<<arr.A[i]<<" ";
    }
    cout<<'\n';
}

void Swap(int *A, int *B){
    int temp = *A;
    *A = *B;
    *B = temp;
}

void Delete(struct Array *arr, int index){
    if (index >= 0 && index <arr->length){
        for (int i = index; i<arr->length-1;i++){
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
    }
}
int LinearSearch(Array arr, int key){
    for (int i = 0; i < arr.length; i++){
        if (arr.A[i] == key){
            return i;
        }
    }
    return -1;
}

 
void Insert(struct Array *arr, int index, int value){
    if (index >= 0 && index <= arr->length){
        for (int i = arr->length; i>index;i--){
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = value;
        arr->length++;
    }else if (index <= arr->size && index > arr->length){
        arr->A[index] = value;
        arr->length++;
    }
}

void Reverse(struct Array *arr){
    int temp;
    int i,j;
    for(i = arr->length-1, j=0;i<j;i--,j++){
        Swap(&arr->A[i], &arr->A[j]);
    }
}

void InsertSort(struct Array *arr, int x){
    int i = arr->length-1;
    if (arr->length == arr->size) return;
    while(i>=0 && arr->A[i]>x){
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr->length++;
}
int isSorted(struct Array arr){
    int i;
    for (i = 0; i < arr.length-1; i++){
        if (arr.A[i]> arr.A[i+1]) return 0;
    }
    return 1;
}

void Rearrange(struct Array *arr){
    int i,j;
    i = 0;
    j = arr->length-1;
    while(arr->A[i]<0) i++;
    while(arr->A[j]>= 0)j--;
    if (i<j) Swap(&arr->A[i], &arr->A[j]);
}

int main(){
    struct Array arr = {{2,-4,30,-15, -69},10, 5};
    Rearrange(&arr);
    Display(arr);
}