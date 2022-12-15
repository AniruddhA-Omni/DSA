#include <iostream>
using namespace std;

int main(){
    string s1;
    cout<<"Enter a string: ";
    getline(cin, s1);
    int vowel = 0, consonant = 0;
    const char* st = s1.c_str();
    for(int i = 0; i < s1.length(); i++){
        if(st[i] == 'a' || st[i] == 'e' || st[i] == 'i' || st[i] == 'o' || st[i] == 'u' || st[i] == 'A' || st[i] == 'E' || st[i] == 'I' || st[i] == 'O' || st[i] == 'U'){
            vowel++;
        }
        else if((st[i] >= 'a' && st[i] <= 'z') || (st[i] >= 'A' && st[i] <= 'Z')){
            consonant++;
        }
    }

    // for(auto x: s1){
    //     if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U'){
    //         vowel++;
    //     }
    //     else if((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z')){
    //         consonant++;
    //     }
    // }
    cout<<"The number of voewls in the string: "<<vowel<<endl;
    cout<<"The number of consonants in the string: "<<consonant<<endl;
}