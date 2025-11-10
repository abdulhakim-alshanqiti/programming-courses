//#include <iostream>
//#include<string>
//#include<iomanip>
//#include "../../Libs/MyLib.h"
//using namespace Input;
//using namespace Output;
//using namespace std;
//
//void PrintMatrix(int matrix[3][3], short rows, short columns) {
//
//	for (int i = 0; i < rows; i++) {
//
//		for (int j = 0; j < columns; j++)
//		{
//			cout << setw(3) << matrix[i][j] << "   ";
//
//		}
//		Printl();
//	}
//
//}
//void FillMatrixWithOrderedNumbers(int matrix[3][3], short rows, short columns) {
//	short count = 0;
//	for (short i = 0; i < rows; i++) {
//
//		for (short j = 0; j < columns; j++)
//		{
//			count++;
//
//			matrix[i][j] = count;
//
//		}
//
//	}
//}
//
//
//
//int main() {
//	SeedRandomness();
//
//	int Matrix[3][3] = {};
//
//
//	FillMatrixWithOrderedNumbers(Matrix, 3, 3);
//
//
//	PrintMatrix(Matrix, 3, 3);
//
//
//	return 0;
//}