//#include <iostream>
//#include<iomanip>
//#include "../../Libs/NumbersLib.h"
//using namespace Numbers;
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
//void FillMatrixWithRandomNumbers(int matrix[3][3], short rows, short columns) {
//	for (int i = 0; i < rows; i++) {
//
//		for (int j = 0; j < columns; j++)
//		{
//
//			matrix[i][j] = RandomNumber(1, 100);
//
//		}
//
//	}
//}
//int main() {
//	SeedRandomness();
//
//	int Matrix[3][3] = {};
//
//	FillMatrixWithRandomNumbers(Matrix, 3, 3);
//
//	PrintMatrix(Matrix, 3, 3);
//
//
//	return 0;
//}