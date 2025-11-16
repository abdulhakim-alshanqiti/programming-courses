#include<iostream>
#include<vector>
using namespace std;
int main() {
	vector<int> vNumbers{ 1, 2, 3, 4, 5 };
	vector<int>::iterator iter;

	for (iter = vNumbers.begin(); iter < vNumbers.end(); iter++) // using pointers
	{
		cout << iter._Ptr << endl;
		cout << *(iter) << endl << endl;
	}

	for (int i = 0; i < vNumbers.size(); i++)
	{
		cout << vNumbers.at(i) << endl;
		cout << vNumbers[i] << endl;
	}
	return 0;
}