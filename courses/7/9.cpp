//#include <iostream>
//#include<string>
//#include<iomanip>
//#include "../../Libs/NumbersLib.h"
//using namespace Input;
//using namespace Output;
//using namespace std;
//
//void PrintMatrix(int matrix[3][3], short rows, short columns) {
//
//	for (short i = 0; i < rows; i++) {
//
//		for (short j = 0; j < columns; j++)
//		{
//
//			printf("%02d   ", matrix[i][j]);
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
//void FillMatrixWithRandomNumbers(int matrix[3][3], short rows, short columns) {
//	for (short i = 0; i < rows; i++) {
//
//		for (short j = 0; j < columns; j++)
//		{
//
//			matrix[i][j] = RandomNumber(1, 100);
//
//		}
//
//	}
//}
//void PrintMiddleRowOfMatrix(int matrix[3][3], short rows, short columns) {
//	short middleRow = rows / 2;
//
//
//
//	for (short i = 0; i < columns; i++)
//	{
//
//
//
//		printf("%02d   ", matrix[middleRow][i]);
//	}
//
//	Printl();
//
//
//}
//void PrintMiddleColumnOfMatrix(int matrix[3][3], short rows, short columns) {
//	short middleColumn = rows / 2;
//
//
//
//	for (short i = 0; i < rows; i++)
//	{
//
//
//		printf("%02d \n", matrix[i][middleColumn]);
//
//
//
//	}
//
//
//
//
//}
//int main() {
//	SeedRandomness();
//
//	int Matrix[3][3];
//
//	FillMatrixWithRandomNumbers(Matrix, 3, 3);
//
//	printf(" This Is The Original Matrix\n");
//	PrintMatrix(Matrix, 3, 3);
//
//	printf(" This Is The Middle Row of Matrix\n");
//	PrintMiddleRowOfMatrix(Matrix, 3, 3);
//
//	printf(" This Is The Middle Column of Matrix\n");
//	PrintMiddleColumnOfMatrix(Matrix, 3, 3);
//
//
//
//	return 0;
//}