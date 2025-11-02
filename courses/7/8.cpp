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
//			matrix[i][j] = RandomNumber(1, 10);
//
//		}
//
//	}
//}
//void MultiplyTwoMatrixes(int SumMatrix[3][3], int matrix1[3][3], int matrix2[3][3], short rows, short columns) {
//
//	for (int i = 0; i < rows; i++) {
//
//		for (int j = 0; j < columns; j++)
//		{
//
//			SumMatrix[i][j] = matrix1[i][j] * matrix2[i][j];
//
//		}
//
//	}
//
//}
//int main() {
//	SeedRandomness();
//
//	int Matrix1[3][3] = {};
//	int Matrix2[3][3] = {};
//	int SumMatrix[3][3] = {};
//
//	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
//	FillMatrixWithRandomNumbers(Matrix2, 3, 3);
//
//	Printl("Matrix 1: ");
//	PrintMatrix(Matrix1, 3, 3);
//	Printl("Matrix 2: ");
//	PrintMatrix(Matrix2, 3, 3);
//
//	Printl("Sum Of The Two: ");
//	MultiplyTwoMatrixes(SumMatrix, Matrix1, Matrix2, 3, 3);
//	PrintMatrix(SumMatrix, 3, 3);
//
//
//
//	return 0;
//}