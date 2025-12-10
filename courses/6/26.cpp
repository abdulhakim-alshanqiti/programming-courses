#include<iostream>
#include<string>
#include"../../libs/MyLib.h"
using namespace std;
using namespace Output;

int main() {
	int a = 10;
	int* p;
	p = &a;

	cout << &a << endl;
	cout << p << endl;



	cout << a << endl;
	cout << p << endl;
	return 0;
}