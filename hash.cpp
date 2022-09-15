#include <iostream>
using namespace std;
#include "chains.h"

int hash2(int key){
    return key%10;
}

void Insert(struct Node* H[], int key){
    int index = hash2(key);
    SortedInsert(&H[index], key);    
}

int main(){
    struct Node* HT[10];
    int i;
    for(i =0; i<10;i++){
        HT[i]=NULL;
    }
    Insert(HT,12);
    Insert(HT,42);
    Insert(HT,69);
    Insert(HT,13);
    Insert(HT,77);
}