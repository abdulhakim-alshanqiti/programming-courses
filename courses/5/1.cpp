#include <iostream>
using namespace std;
string RowSeparator(int i) {
	string Separator = "\n";
	while (i >= 1) {
		Separator += "-";
		i--;
	}

	return Separator;
}

void printTableHeader() {
	cout << "\t\t\t Multiplication table from 1 to 10\n\n";
	cout << "\t ";
	for (int i = 1; i <= 10; i++) {
		cout << i << "\t";
	}
	cout << RowSeparator(86);
}



void printRowsAndColumns() {
	for (int i = 1; i <= 10; i++) {
		cout << endl;

		cout << i << "\t|" ;

		for (int j = 1; j <= 10; j++) {
				cout << i * j << "\t";
		}

	}
}

void printMultiplicationTable() {
	printTableHeader();
	printRowsAndColumns();
}

int main()
{
	printMultiplicationTable();
	
	return 0;
}