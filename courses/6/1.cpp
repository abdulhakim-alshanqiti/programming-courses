#include<iostream>
#include "../../Libs/MyLib.h"
using namespace std;
using namespace Input;

int main() {
	SeedRandomness();
	cout << RandomNumber(1, 10) << endl;

	return 0;
}