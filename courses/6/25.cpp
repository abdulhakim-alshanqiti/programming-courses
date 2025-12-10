#include<iostream>
#include<string>
#include"../../libs/MyLib.h"
using namespace std;
using namespace Output;

int main() {
	int a = 10;
	int& x = a;

	cout << &a << endl;
	cout << &x << endl;

	x = 20;

	cout << a << endl;
	cout << x << endl;
	return 0;
}