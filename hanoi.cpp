#include <iostream>
using namespace std;

void TOH(int n, int a, int b, int c){
        if (n>0){
            TOH(n-1, a, c, b);
            cout<<"Move disc "<<n<<" from peg "<<a<<" to peg "<<c<<endl;
            TOH(n-1, b, a, c);
        }}

int main(){
    TOH(4,1,2,3);
}