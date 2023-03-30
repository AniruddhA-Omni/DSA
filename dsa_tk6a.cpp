#include <iostream>
#include <string>

using namespace std;

int main() {
    string M = "THIS IS A SIMPLE EXAMPLE";
    string P = "SIMPLE";
    int m = M.length();
    int p = P.length();
    int i, j;

    for (i = 0; i <= m - p; i++) {
        j = 0;
        while (j < p && M[i+j] == P[j]) j++;
        if (j == p) {
            cout << "Pattern found at index " << i << endl;
        }
    }
    return 0;
}
