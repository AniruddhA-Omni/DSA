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
    void create(){
        for(int i=0;i<n;i++){
            cout<<"Enter coefficient and exponent of term "<<i+1<<endl;
            cin>>terms[i].coeff>>terms[i].exp;
        }
    }
    void display(){
        for(int i=0;i<n;i++){
            if (i==n-1){
                cout<<terms[i].coeff<<"x^"<<terms[i].exp<<" = 0 ";
            }else{
                cout<<terms[i].coeff<<"x^"<<terms[i].exp<<" + ";
            }
        }
        cout<<endl;
    }
    Poly operator+(Poly &p){
        Poly q(n+p.n);
        int i,j,k;
        i=j=k=0;
        while(i<n && j<p.n){
            if(terms[i].exp==p.terms[j].exp){
                q.terms[k].coeff = terms[i].coeff + p.terms[j].coeff;
                q.terms[k].exp = terms[i].exp;
                i++;
                j++;
                k++;
            }
            else if(terms[i].exp<p.terms[j].exp){
                q.terms[k].coeff = terms[j].coeff;
                j++;
                k++;
            }
            else{
                q.terms[k].coeff = p.terms[i].coeff;
                i++;
                k++;
            }
        }
        for(; i<n;i++) q.terms[k++] = terms[i];
        for(; j<p.n;j++) q.terms[k++] = p.terms[j]; 
        q.n = k;
        return q;
    }
};

int main(){
    int n;
    cout<<"Enter number of terms in first polynomial"<<endl;
    cin>>n;
    Poly p1(n);
    p1.create();
    p1.display();
    cout<<"Enter number of terms in second polynomial"<<endl;
    cin>>n;
    Poly p2(n);
    p2.create();
    p2.display();
    Poly q = p1+p2;
    q.display();
    return 0;
}