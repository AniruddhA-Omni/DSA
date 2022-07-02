#include <iostream>
using namespace std;

class Term{
public:
int coeff;
int exp;
};

class Poly{
private:
int n;
Term *terms;
public:
    Poly(int n){
        this->n = n;
        terms = new Term[n];
    }

};