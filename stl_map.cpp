#include <iostream>
#include <map>
#include <string>
using namespace std;

void display(map<string, int> &m){
    for(auto i :m){
        cout << i.first << " " << i.second << endl;
    }
    cout<<endl;
}


int main(){
    map<string, int> m1;
    map<string, int> m2{{"a",1},{"b",2},{"c",3}};
    map<string, int> m3(m2);
    m1["ani"] = 10;
    m1["bk"] = 25;
    m1["cp"] = 33;
    display(m1);
    display(m2);
    //display(m2);
    m3.insert({{"d",4},{"e",5},{"f",6}});
    display(m3);
    cout<<"MAx size: "<<m3.max_size()<<endl;
}