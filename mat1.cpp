#include <iostream>
using namespace std;


// Diagonal matrix
class Diagonal{
private:
    int *A;
    int n;
public:
    Diagonal(){
        n = 2;
        A = new int[2];
    }
    Diagonal(int n){
        this->n = n;
        A = new int[n];
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    ~Diagonal(){
        delete []A;
    }
};

void Diagonal::Set(int i, int j, int x){
    if (i == j) A[i-1] = x;
}

int Diagonal::Get(int i, int j){
    if (i == j){
        return A[i-1];
    }
    return 0;
}

void Diagonal::Display(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(i == j){
                cout<<A[i]<<" ";
            }else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}
//// LowerTriangular
class Lower{
private:
    int *A;
    int n;
public:
    Lower(){
        n = 2;
        A = new int[2];
    }
    Lower(int n){
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    ~Lower(){
        delete []A;
    }
};

void Lower::Set(int i, int j, int x){
    int index = i*(i-1)/2 + (j-1);
    if (i >= j) A[index] = x;
}

int Lower::Get(int i, int j){
    int index = i*(i-1)/2 + (j-1);
    if (i >= j){
        return A[index];
    }
    return 0;
}

void Lower::Display(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if(i >= j){
                cout<<A[i*(i-1)/2 + (j-1)]<<" ";
            }else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}

//// UpperTriangular matrix
class Upper{
private:
    int *A;
    int n;
public:
    Upper(){
        n = 2;
        A = new int[2];
    }
    Upper(int n){
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    ~Upper(){
        delete []A;
    }
};

void Upper::Set(int i, int j, int x){
    int index = j*(j-1)/2 + (i-1);
    if (i <= j) A[index] = x;
}

int Upper::Get(int i, int j){
    int index = j*(j-1)/2 + (i-1);
    if (i <= j){
        return A[index];
    }
    return 0;
}

void Upper::Display(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if(i <= j){
                cout<<A[j*(j-1)/2 + (i-1)]<<" ";
            }else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}


int main(){
    Diagonal d(4);
    d.Set(1,1,5);
    d.Set(2,2,8);
    d.Set(3,3,69);
    d.Set(4,4,13);
    d.Display();
    cout<<endl;
    Lower l(4);
    l.Set(1,1,5);
    l.Set(2,2,8);
    l.Set(3,3,69);
    l.Set(4,4,9);
    l.Set(4,1,13);
    l.Set(3,2,3);
    l.Set(2,1,30);
    l.Display();
    cout<<endl;
    Upper u(4);
    u.Set(1,1,5);
    u.Set(2,2,8);
    u.Set(3,3,69);
    u.Set(4,4,9);
    u.Set(1,4,13);
    u.Set(2,3,3);
    u.Set(1,2,30);
    u.Display();
    return 0;
}