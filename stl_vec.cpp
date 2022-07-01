#include <iostream>
#include <vector>
using namespace std;

void display(vector<int> &v){
    for(auto i :v){
        cout << i << " ";
    }
    cout << endl;
}




int main(){
    vector<int> vec1;
    vector<int> vec2(10);
    vector<int> vec3(10, 42);
    vector<int> vec4{10, 42, 100, 200};
    vector<int> vec5(vec4);
    vector<int> vec6(vec4.begin(), vec4.end());
    vector<int> vec7(vec4.rbegin(), vec4.rend());
    vector<int> vec8(vec4.cbegin(), vec4.cend());
    vector<int> vec9(vec4.crbegin(), vec4.crend());
    vector<int> vec10(vec4.size());
    vector<int> vec11(vec4.size(), 42);
    vector<int> vec12(vec4.size(), 42, allocator<int>());
    vector<char> vec13(10, 'a');
    display(vec4);
    int ele;
    for(int i = 0;i<4;i++){
        cout<<"Enter elements: ";
        cin>>ele;
        vec1.push_back(ele);
    }
    display(vec1);
    vec1.push_back(10);
    display(vec1);
    vec1.pop_back();
    display(vec1);
    vector<int> :: iterator it = vec1.begin();
    vec1.insert(it+2,100);
    display(vec1);
}