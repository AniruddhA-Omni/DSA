#include <iostream>
using namespace std;

int max(int a, int b){
    return (a >b)? a:b;}

    // Code for fractional knapsack
    float fractional_knapsack(int C, int wt[], int val[], int n){
        int i, j;
        float x[20], tp = 0;
        for(i = 0; i < n; i++)
            x[i] = 0.0;
        for(i = 0; i < n; i++){
            if(wt[i] > C)
                break;
            else{
                x[i] = 1.0;
                tp = tp + val[i];
                C = C - wt[i];
            }
        }
        if(i < n)
            x[i] = C / wt[i];
        tp = tp + (x[i] * val[i]);
        return tp;
    }

    int main(){
        int profit[] = {30,40,45,77,90};
        int weight[] = {5,10,15,22,25};
        int C = 60; // Capacity of knapsack
        int n = sizeof(profit) / sizeof(profit[0]);
        cout << fractional_knapsack(C, weight, profit, n);
        return 0;
    }