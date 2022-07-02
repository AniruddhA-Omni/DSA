#include <iostream>
#include <string>

using namespace std;


// compare strings
void comp(){

    char A[] = "Painter";
    char B[] = "Painting";
    int i, j ;
    for(i =0, j=0; A[i] != '\0' && B[j] != '\0'; i++, j++){
        if ((A[i] >= 65 && A[i] <= 90) || (B[j]>= 65 && B[j] <= 90)){
            A[i] += 32;
            B[j] += 32;
        }
        if(A[i] != B[j]){
            break;
        }
    }
    if (A[i] == '\0' && B[j] == '\0'){
        cout << "Strings are equal" << endl;
    }
    else{
        cout << "Strings are not equal" << endl;
    }
}

// finding duplicates in string
void dup(){
    char A[] = "FindingDuplicatesInString";
    int H[25] = {0};
    int i, temp;
    for(i = 0; A[i] != '\0'; i++){
        if (A[i] >= 65 && A[i] <= 90) A[i] += 32;
    } // O(n)
    for(i = 0; A[i] != '\0'; i++){
        temp = H[A[i] - 'a'];
        if (H[A[i] - 'a'] >= 0){
            temp++;
            H[A[i] - 'a'] = temp;
        }
    } //O(n)
    for(i = 0; A[i] != '\0'; i++){
        if (H[A[i] - 'a'] > 1){
            cout<< A[i] << " "<< H[A[i]-'a'] << endl;
        }
    } //O(n)
}

// finding anagrams in string

void ana(){
    char A[] = "decimal";
    char B[] = "mdeical";
    int i, H[26] = {0};
     for(i = 0; A[i] != '\0'; i++){
        H[A[i] - 'a'] += 1;
     } //O(n)
    for(i = 0; B[i] != '\0'; i++){
        H[B[i] - 'a'] -= 1;
        if (H[B[i] - 'a'] < 0){
            cout << "Strings are not anagrams" << endl;
            return;
        }
    } //O(n)
    cout << "Strings are anagrams" << endl;
}

//permutations of a string
void perm(){
    char A[] = "abc";
    int i, j, k;
    int n = sizeof(A) / sizeof(A[0]);
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            for(k = 0; k < n; k++){
                cout << A[i] << A[j] << A[k] << endl;
            }
        }
    }
}



int main(){
    dup();
    ana();
    perm();
    return 0;
}