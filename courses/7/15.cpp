//#include <iostream>
//#include<string>
//#include<iomanip>
//#include "../../Libs/NumbersLib.h"
//using namespace Numbers;
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
//
//void FillMatrixWithRandomNumbers(int matrix[3][3], short rows, short columns) {
//	for (short i = 0; i < rows; i++) {
//
//		for (short j = 0; j < columns; j++)
//		{
//
//			matrix[i][j] = RandomNumber(1, 10);
//
//		}
//
//	}
//}
//
//short NumberFrequncyInArray(int NumberToCheck, int Matrix1[3][3], short rows, short columns) {
//	short counter = 0;
//	for (short i = 0; i < rows; i++)
//	{
//
//
//		for (short j = 0; j < columns; j++) {
//
//			if (Matrix1[i][j] == NumberToCheck)
//			{
//
//				counter++;
//
//			}
//
//		}
//	}
//	return counter;
//}
//void PrintNumberFrequncyInArray(int NumberToCheck, int Matrix1[3][3], short rows, short columns) {
//
//	printf("The Number [%d] Frequncy in array is %d", NumberToCheck, NumberFrequncyInArray(NumberToCheck, Matrix1, 3, 3));
//
//}
//int main() {
//	SeedRandomness();
//
//	int Matrix1[3][3];
//	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
//
//	Printl("Matrix 1:");
//	PrintMatrix(Matrix1, 3, 3);
//
//	int number = ReadNumber("Which Number You Want To Check Frequncy For ?");
//	PrintNumberFrequncyInArray(number, Matrix1, 3, 3);
//
//
//	return 0;
//}