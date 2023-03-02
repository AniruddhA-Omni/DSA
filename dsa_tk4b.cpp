#include <iostream>
#include <vector>
using namespace std;

void swap(int *a, int *b){
  int temp = *b;
  *b = *a;
  *a = temp;
}

void heapify(vector<int> &hT, int i){
  int size = hT.size();
  int smallest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  if (l < size && hT[l] < hT[smallest])
    smallest = l;
  if (r < size && hT[r] < hT[smallest])
    smallest = r;

  if (smallest != i)
  {
    swap(&hT[i], &hT[smallest]);
    heapify(hT, smallest);
  }
}

void insert(vector<int> &hT, int newNum){
  int size = hT.size();
  if (size == 0){
    hT.push_back(newNum);
  }else{
    hT.push_back(newNum);
    for (int i = size / 2 - 1; i >= 0; i--)
    {
      heapify(hT, i);
    }
  }
}

void deleteNode(vector<int> &hT, int num){
  int size = hT.size();
  int i;
  for (i = 0; i < size; i++)
  {
    if (num == hT[i])
      break;
  }
  swap(&hT[i], &hT[size - 1]);

  hT.pop_back();
  for (int i = size / 2 - 1; i >= 0; i--)
  {
    heapify(hT, i);
  }
}

void printArray(vector<int> &hT){
  for (int i = 0; i < hT.size(); ++i)
    cout << hT[i] << " ";
  cout << "\n";
}

int main(){
  vector<int> heapTree;
  int A[] = {14,12,3,5,9,7,5,4,12,13,22};
  int n = sizeof(A) / sizeof(A[0]);
  for(int i = 0; i <n; i++) insert(heapTree, A[i]);
  cout << "Min-Heap array: ";
  printArray(heapTree);
  deleteNode(heapTree, 12);
  cout << "After deleting an element: ";
  printArray(heapTree);
}