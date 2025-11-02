//#include<iostream>
//#include<vector>
//using namespace std;
//int main() {
//	vector<int> num{ 1, 2, 3, 4, 5 };
//	cout << "\n\n using .at(i) \n";
//	cout << "Element at Index 0: " << num.at(0) << endl;
//	cout << "Element at Index 2: " << num.at(2) << endl;
//	cout << "Element at Index 4: " << num.at(4) << endl; // this will throw an exception if the element dosen't exist and in relese mode it will crash the program and any code bellow it won't run
//
//	cout << "\n\n using [i]\n";
//	cout << "Element at Index 0: " << num[0] << endl;
//	cout << "Element at Index 2: " << num[2] << endl;
//	cout << "Element at Index 4: " << num[4] << endl; // this will give a warning in debug mode "vector subscript out of range" and in release mode it will print garbage data from memory at index 5
//
//
//
//
//	return 0;
//}