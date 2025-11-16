#include<iostream>
#include<string>
#include<cctype>
using namespace std; int main() {
	char x, w;
	x = toupper('a');
	w = tolower('A');
	cout << "converting a to A: " << x << endl;
	cout << "converting A to a: " << w << endl;
	// Digits (A to Z)
	// returns zero if not, and non zero of yes  
	cout << "isupper('a') " << isupper('a') << endl;
	// lower case (a to z)
	// returns zero if not, and non zero of yes
	cout << "islower('A') " << islower('A') << endl;
	// Digits (0 to 9)
	// returns zero if not, and non zero of yes
	cout << "isdigit(8) " << isdigit(8) << endl;
	cout << "isdigit('8') " << isdigit('8') << endl;
	// punctuation characters are !"#$%&'()*+,-./:;<=>?@[\]^_`{|}~
	// returns zero if not, and non zero of yes
	cout << "ispunct('A') " << ispunct('A') << endl;

	return 0;
}