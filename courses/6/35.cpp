//#include<iostream>
//using namespace std;
//int main() {
//	int num;
//	cout << "Enter total number of students: ";
//	cin >> num;
//
//	float* ptrToArrayOfStudentGrades;
//	// memory allocation of num number of floats  
//	// Grades are Floats so you can have 96.8 for example
//	ptrToArrayOfStudentGrades = new float[num];
//
//
//	cout << "Enter grades of students." << endl;
//	for (int i = 0; i < num; i++) {
//		cout << "Student" << i + 1 << ": ";
//		cin >> *(ptrToArrayOfStudentGrades + i);
//	}
//
//	cout << "\nDisplaying grades of students." << endl;
//	for (int i = 0; i < num; i++) {
//		cout << "Student" << i + 1 << ": " << *(ptrToArrayOfStudentGrades + i) << endl;
//	}
//
//	// ptrToArrayOfStudentGrades memory is released
//	delete[] ptrToArrayOfStudentGrades;
//
//
//
//	return 0;
//}