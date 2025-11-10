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
//			matrix[i][j] = RandomNumber(1, 5);
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
//int SumOfMatrix(int matrix[3][3], short rows, short columns) {
//
//
//	int sum = 0;
//
//	for (short i = 0; i < rows; i++)
//	{
//
//
//		for (short j = 0; j < columns; j++) {
//			sum += matrix[i][j];
//
//		}
//
//	}
//	return sum;
//}
//bool IsTheMatrixesAnIdentity(int Matrix1[3][3], short rows, short columns) {
//	for (short i = 0; i < rows; i++)
//	{
//
//
//		for (short j = 0; j < columns; j++) {
//
//			if ((i == j) && Matrix1[i][j] != 1)
//				return false;
//			else if ((i != j) && Matrix1[i][j] != 0)
//				return false;
//
//
//
//
//		}
//	}
//	return true;
//}
//void PrintTheResult(bool Identity) {
//	if (Identity)
//		Printl("Yes The Matrix Is Identity");
//	else
//		Printl("No The Matrix Isn't Identity");
//}
//int main() {
//	SeedRandomness();
//
//	int Matrix1[3][3] = {
//		{1,0,0},
//		{0,0,0},
//		{0,0,1}
//	};
//
//	Printl("Matrix 1:");
//	PrintMatrix(Matrix1, 3, 3);
//
//
//	PrintTheResult(IsTheMatrixesAnIdentity(Matrix1, 3, 3));
//
//
//	return 0;
//}