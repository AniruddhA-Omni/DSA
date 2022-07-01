#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int main(){
    // Function Objects (Functor)
    int arr[] = {1, 69, 75, 5, 44, 33, 12, 45, 67, 89, 90};
    sort(arr, arr+11, greater<int>());
    for(auto i : arr){
        cout << i << " ";
    }
    cout << endl;

}