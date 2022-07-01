#include <iostream>
using namespace std;

// find multiple missing elements in a sorted array
// int main(){
//     int A[] = {1, 2, 3, 4,6, 7, 8, 10, 12, 13};
//     int diff, i;
//     int n = sizeof(A)/sizeof(A[0]);
//     diff = A[0] - 0;
//     for(i =0;i<n;i++){
//         if(A[i]-i != diff){
//             while(diff < A[i]-i){
//                 cout<<i + diff<<" ";
//                 diff++;
//             }
//         }
//     }
// }

// find multiple missing elements in an unsorted array

// find duplicate elements in an sorted array
// int main(){
//     int A[] = {3,6,8,8,10,12,15,15,15,20};
//     int n = sizeof(A)/sizeof(A[0]);
//     int i;
//     for(i =0 ;i<n-1;i++){
//         if(A[i] == A[i+1]){
//             cout<<"Duplicate value "<<A[i]<<" at index "<<i+1<<". \n";
//         }
//     }
// }

// find duplicate elements in an unsorted array
int main(){
    int A[] = {6,3,8,8,12,9,15,15,15,69,30};
    int n = sizeof(A)/sizeof(A[0]);
    int i, j, count;
    for(i = 0; i<n-1;i++){
        count = 1;
        if(A[i] != -1){
            for(j = i+1; j<n;j++){
                if(A[i] == A[j]){
                    A[j] = -1;
                    count++;
                }
            }
            if(count > 1){
                cout<<A[i]<<" "<<count<<"\n";
            }
        }
    }
}
