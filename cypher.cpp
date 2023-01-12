#include <iostream>
using namespace std;


string encrypt(string text, int s){
	string result = "";
	// traverse text
	for (int i = 0; i < text.length(); i++) {
		// apply transformation to each character
		// Encrypt Uppercase letters
		if (isupper(text[i]))
			result += char(int(text[i] + s - 65) % 26 + 65);

		// Encrypt Lowercase letters
		else
			result += char(int(text[i] + s - 97) % 26 + 97);
	}
	// Return the resulting string
	return result;
}

// Driver program to test the above function
int main()
{
	string text1 = "ATTACKATONCE";
    string text2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int s1 = 4;
	int s2 = 23;
	cout << "Text : " << text1;
	cout << "\nShift: " << s1;
	cout << "\nCipher: " << encrypt(text1, s1);
    cout << "Text : " << text2;
	cout << "\nShift: " << s2;
	cout << "\nCipher: " << encrypt(text2, s2);
	return 0;
}
