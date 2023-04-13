#include <bits/stdc++.h>
using namespace std;

struct Item{
    int data;
    int weight;
    Item(int data, int weight){
        this->data = data;
        this->weight = weight;
    }
};

bool comp(Item a, Item b){
    double r1 = (double)a.weight / a.data;
    double r2 = (double)b.weight / b.data;
    return r1 > r2;
}

double frax(int W, struct Item arr[], int n){
    double final_value = 0.0;
    double current_weight = 0.0;

    for(int i = 0 ; i<n;i++){
        if (current_weight+arr[i].weight <= W ){
            final_value += arr[i].data;
            current_weight += arr[i].weight;
        }else{
            double remain = W- current_weight;
            final_value += (double)arr[i].data * (double)remain / (double)arr[i].weight;
            break;
        }
    }
    return final_value;
}

int main(){
    int W = 50;
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << frax(W, arr, n);
    return 0;
}