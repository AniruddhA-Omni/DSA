#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
using namespace std;

int main(){
    clock_t start, end;
    start = clock();
    ///1d array
    int *p = new int[5];

    delete [] p;
    ///2d array part 1
    int *A[3]; //3 rows, 3 pointers

    for(int i = 0; i < 3; i++){
        A[i] = new int[4];
    }
    A[1][2] = 5;
    for(int i = 0; i < 3; i++){
        delete [] A[i];
    }
    /// 2d array part 2
    int **B = new int*[3];
    for(int i = 0; i < 3; i++){
        B[i] = new int[4];
    }
    B[1][2] = 5;
    for(int i = 0; i < 3; i++){
        delete [] B[i];
    }
    ///
    end = clock();
    cout << "Execution Time: " << (double)(end - start) / CLOCKS_PER_SEC <<setprecision(6)<<" sec"<<endl;
}
