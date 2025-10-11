//#include <iostream>
//using namespace std;
//string RowSeperator(int i) {
//	string seperator = "\n";
//	while (i >= 1) {
//		seperator += "-";
//		i--;
//	}
//
//	return seperator;
//}
//
//void printTableHeader() {
//	cout << "\t\t\t Multiplication table from 1 to 10\n\n";
//	cout << "\t ";
//	for (int i = 1; i <= 10; i++) {
//		cout << i << "\t";
//	}
//	cout << RowSeperator(86);
//}
//
//
//
//void printRowsAndColumns() {
//	for (int i = 1; i <= 10; i++) {
//		cout << endl;
//
//		cout << i << "\t|" ;
//
//		for (int j = 1; j <= 10; j++) {
//				cout << i * j << "\t";
//		}
//
//	}
//}
//
//void printMultiplicationTable() {
//	printTableHeader();
//	printRowsAndColumns();
//}
//
//int main()
//{
//	printMultiplicationTable();
//	
//	return 0;
//}