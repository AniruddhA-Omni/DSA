#include <iostream>
using namespace std;
#include "chains.h"
#define size 10

// Chaining
int hash2(int key){
    return key%10;
}
void Insert1(struct Node* H[], int key){
    int index = hash2(key);
    SortedInsert(&H[index], key);    
}


// Linear Probing
int hash3(int key){
    return key%size;
}
int probe(int H[], int key){
    int index=hash3(key);
    int i = 0;
    while(H[(index+i)%size]!=0)
        i++;
    return (index+i)%size;
}
void Insert2(int H[], int key){
    int index = hash3(key);
    if(H[index] != 0)
        index = probe(H,key);
    H[index]=key;
}
int Search2(int H[], int key){
    int index=hash3(key);
    int i = 0;
    while(H[(index+i)%size]!=0)
        i++;
    return (index+i)%size;

}


// Quadratic Probing
int hash4(int key){
    return key%size;
}
int probe2(int H[], int key){
    int index=hash3(key);
    int i = 0;
    while(H[(index+i*i)%size]!=0)
        i++;
    return (index+i*i)%size;
}
void Insert3(int H[], int key){
    int index = hash4(key);
    if(H[index] != 0)
        index = probe(H,key);
    H[index]=key;
}
int Search3(int H[], int key){
    int index=hash4(key);
    int i = 0;
    while(H[(index+i*i)%size]!=0)
        i++;
    return (index+i*i)%size;

}


int main(){
    struct Node* HT[10];
    int i;
    for(i =0; i<10;i++){
        HT[i]=NULL;
    }
    Insert1(HT,12);
    Insert1(HT,42);
    Insert1(HT,69);
    Insert1(HT,13);
    Insert1(HT,77);
}