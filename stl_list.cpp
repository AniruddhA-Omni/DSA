#include <iostream>
#include <list>
using namespace std;

void display(list<int> &l){
    for(auto i :l){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    list<int> list1;
    list<int> l2(10,5);

    list1.push_back(10);
    list1.push_back(20);
    list1.push_back(30);
    list1.push_back(40);
    list1.push_back(50);

    display(list1);
    list<int>::iterator it1 = list1.begin();
    list1.remove(20);
    display(l2);
    cout<<"After merging: "<<endl;
    l2.merge(list1);
    display(l2);
    l2.sort();
    display(l2);
    l2.reverse();
    display(l2);
    l2.unique();
    display(l2);

}