//#include <iostream>
//#include<string>
//#include "../../Libs/MyLib.h"
//using namespace Input;
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
//		printf("\n");
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
//short NumberFrequncyInArray(int Matrix1[3][3], int NumberToCheck, short rows, short columns) {
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
//
//bool IsNumberInMatrix(int Matrix1[3][3], int NumberToCheck, short rows, short columns) {
//	for (short i = 0; i < rows; i++)
//	{
//
//
//		for (short j = 0; j < columns; j++) {
//
//			if (Matrix1[i][j] == NumberToCheck)
//			{
//
//				return true;
//
//			}
//
//		}
//	}
//
//	return false;
//}
//
//void PrintIsNumberInMatrix(int Matrix1[3][3], int NumberToCheck, short rows, short columns) {
//	if (IsNumberInMatrix(Matrix1, NumberToCheck, rows, columns))
//		printf("The Number [%d] dose exist", NumberToCheck);
//	else
//		printf("The Number [%d] dosen't exist", NumberToCheck);
//
//}
//int main() {
//	SeedRandomness();
//
//	int Matrix1[3][3];
//	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
//
//	printf("Matrix 1:\n");
//	PrintMatrix(Matrix1, 3, 3);
//
//
//	int NumberToCheck = ReadNumber("Enter The Number You Want To Look For In Matrix");
//	PrintIsNumberInMatrix(Matrix1, NumberToCheck, 3, 3);
//
//
//	return 0;
//}