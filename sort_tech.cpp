#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;

struct Node{
    int data;
    Node* next = NULL;
};

// Miscellaneous funcitons
void swap(int *x, int *y){
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}

// Sorting Algorithms
void BubbleSort(int A[], int n){
    for(int i = 0; i < n; i++){
        int flag = 0;
        for(int j = 0; j < n-i-1;j++){
            if(A[j] > A[j+1]){
                swap(A[j], A[j+1]);
                flag = 1;
            }
        }
        if (flag == 0) break;
    }
}

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

void SelectionSort(int A[], int n){
    for(int i = 0; i<n-1;i++){
        int x = A[i];
        int j, k;
        for(j = k = i;j<n;j++){
            if(A[j] < A[k])
                k = j;
        }
        swap(A[i], A[k]);
    }
}

int Partition(int A[],  int l, int h){
    int pivot = A[l];
    int i = l, j = h;
    do{
        do{i++;} while(A[i]<= pivot);
        do{j++;} while(A[j]> pivot);
        if (i < j){
            swap(A[i], A[j]);
        }
    }while(i<j);
    swap(A[l], A[j]);
    return j;
}

void QuickSort(int A[], int l, int h){
    int j;
    if(l<h){
        j = Partition(A,l,h);
        QuickSort(A,l,j);
        QuickSort(A, j+1, h);
    }
}

void Merge(int A[], int B[], int m, int n){
    int i, j, k;
    int C[m+n];
    i = j = k = 0;
    while(i <m && j<n){
        if(A[i]< B[j]) C[k++] = A[i++];
        else C[k++] = B[j];
    }
    for(; i<m; i++)
        C[k++] = A[i];
    for(; j<n; j++)
        C[k++] = B[j];  
     
}

void MergeSort(int A[], int l, int h, int mid){
    int i, j, k;
    int C[h++];
    i = l; j = mid +1; k = l;
    while(i <=mid && j<=h){
        if(A[i]< A[j]) C[k++] = A[i++];
        else C[k++] = A[j];
    }
    for(; i<=mid; i++)
        C[k++] = A[i];
    for(; j<=h; j++)
        C[k++] = A[j];  
    for(i = l;i<=h;i++){
        A[i] = C[i];
    }
}

void IMergeSort(int A[], int n){
    int p, i, l, mid, h;
    for(p=2; p<=n; p=p*2){
        for(i = 0; i+p-1 <n;i =i+p){
            l = i;
            h = i+p-1;
            mid = ((l+h)/2);
            MergeSort(A, l, mid, h);
        }
    }
    if (p/2 < n){
        MergeSort(A, 0, p/2, n-1);
    }
}

void RMergeSort(int A[], int l, int h){
    int mid;
    if(l<h){
        mid = (l+h)/2;
        RMergeSort(A, l, mid);
        RMergeSort(A, mid+1,h);
        MergeSort(A, l, mid, h);
    }
}

void CountSort(int A[], int n){
    int max = INT32_MIN, i,j;
    int *C;
    int temp = 0;
    while(temp<n){
        if(A[temp]>max){
            max = A[temp];
        }
        temp++;
    }
    C = new int[max+1];
    for(i = 0;i<max+1;i++){
        C[i]=0;
    }
    for(i = 0;i<n;i++){
        C[A[i]]++;
    }
    i =0; j =0;
    while(i<max+1){
        if(C[i]>0){
            A[j++] = i;
            C[i]--;
        }else{
            i++;
        }
    }
    delete []C;
}

void BinSort(int A[], int n){
    int max = INT32_MIN, i,j;
    Node **B;
    int temp = 0;
    while(temp<n){
        if(A[temp]>max){
            max = A[temp];
        }
        temp++;
    }
    B = new Node*[max+1];
    for(i = 0;i<max+1;i++){
        B[i]=NULL;
    }
    Node* p;
    for(i = 0;i<n;i++){
        p->data = A[i];
        p->next = NULL;
        B[A[i]]->next = p;
    }
    i =0; j =0;
    while(i<max+1){
        while(B[i]->next!=NULL){
            A[j++] = B[i]->data;
            p = NULL;
            B[i]->next= p;
        }
        i++;
    }
    delete []B;
}


void ShellSort(int A[], int n){
    int gap, i, j;
    for(gap = n/2; gap>1;gap/=2){
        for(i=gap; i<n;i++){
            int temp = A[j];
            j = i-gap;
            while(j>0 && A[j]>temp){
                A[j+gap]=A[j];
                j= j-gap;
            }
            A[j+gap] = temp;
        }
    }
}


int main(){
    int A[] = {30, 20, 15, 5, 10, 8, 12};
    int n = sizeof(A)/sizeof(A[0]);

    auto start = high_resolution_clock::now();
    SelectionSort(A, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    cout<<"Sorted Array: ";
    for(int i = 0; i < n; i++){
        cout << A[i] << " ";
    }
    cout << endl;

    cout << "Time taken by function: "
         << duration.count() << " nanoseconds" << endl;

}