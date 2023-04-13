// #include<bits/stdc++.h>
// using namespace std;

// struct Item {
//     int weight;
//     int value;
// };

// bool cmp(struct Item a, struct Item b) {
//     double r1 = (double)a.value / (double)a.weight;
//     double r2 = (double)b.value / (double)b.weight;
//     return r1 > r2;
// }

// double fractionalKnapsack(int W, struct Item arr[], int n) {
//     sort(arr, arr + n, cmp);
//     int curWeight = 0;
//     double finalvalue = 0.0;
//     for (int i = 0; i < n; i++) {
//         if (curWeight + arr[i].weight <= W) {
//             curWeight += arr[i].weight;
//             finalvalue += arr[i].value;
//         }
//         else {
//             int remain = W - curWeight;
//             finalvalue += arr[i].value * ((double)remain / (double)arr[i].weight);
//             break;
//         }
//     }
//     return finalvalue;
// }

// int main() {
//     int W = 60;
//     Item arr[] = {{5, 30}, {10, 40}, {15, 45}, {22, 77}, {25, 90}};     // {weight, value}
//     int n = sizeof(arr) / sizeof(arr[0]);
//     cout << "Maximum value we can obtain = " << fractionalKnapsack(W, arr, n) << endl;
//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int value;
};

bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item> items) {
    sort(items.begin(), items.end(), cmp);

    double result = 0.0;
    int current_weight = 0;

    for (int i = 0; i < items.size(); i++) {
        if (current_weight + items[i].weight <= W) {
            result += items[i].value;
            current_weight += items[i].weight;
        }
        else {
            int remaining_weight = W - current_weight;
            result += (double)remaining_weight * items[i].value / items[i].weight;
            break;
        }
    }

    return result;
}

int main() {
    vector<Item> items = {{5, 30}, {10, 40}, {15, 45}, {22, 77}, {25, 90}};
    int W = 60;

    double max_value = fractionalKnapsack(W, items);

    cout << "Maximum value we can obtain = " << max_value << endl;

    return 0;
}
