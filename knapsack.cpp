#include <iostream>
using namespace std;

// A utility function that returns
// maximum of two integers
float max(float a, float b) { return (a > b) ? a : b; }

// Returns the maximum value that
// can be put in a knapsack of capacity W
float knapSack(int C, int wt[], int val[], int n){
	if (n == 0 || C == 0)
		return 0;

	if (wt[n - 1] > C)
		return knapSack(C, wt, val, n - 1);

	// Return the maximum of two cases:
	// (1) nth item included
	// (2) not included
	else
		return max(val[n - 1]+ knapSack(C - wt[n - 1], wt, val, n - 1), knapSack(C, wt, val, n - 1));
}

// Driver code
int main(){
	int profit[] = {2,3,1,4};
	int weight[] = {3,4,6,5};
	int C = 8; // Capacity of knapsack
	int n = sizeof(profit) / sizeof(profit[0]);
	cout << knapSack(C, weight, profit, n);
	return 0;
}

// This code is contributed by rathbhupendra
