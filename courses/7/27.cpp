#include <iostream>
#include<string>
#include "../../libs/MyLib.h"
#include <vector>
using namespace Input;
using namespace std;





char InvertCase(char Char) {


	return  isupper(Char) ? tolower(Char) : toupper(Char);

}

int main() {

	char myChar = ReadChar("Enter a Character");



	cout << "  Char before Inversion \n" << myChar << endl;

	cout << "  Char After Inversion \n" << InvertCase(myChar) << endl;
	return 0;
}