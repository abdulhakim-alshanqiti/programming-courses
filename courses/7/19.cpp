//#include <iostream>
//#include<string>
//#include "../../Libs/NumbersLib.h"
//#include <vector>
//using namespace Numbers;
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
//void FillIntersectedNumbers(vector<int>& IntersectedNumbers, int Matrix1[3][3], int Matrix2[3][3], short rows, short columns) {
//
//	int NumberToCheck = 0;
//
//	for (short i = 0; i < rows; i++)
//	{
//
//
//		for (short j = 0; j < columns; j++) {
//			NumberToCheck = Matrix1[i][j];
//
//			if (IsNumberInMatrix(Matrix2, NumberToCheck, rows, columns))
//			{
//
//				IntersectedNumbers.push_back(NumberToCheck);
//
//			}
//
//		}
//	}
//
//
//}
//void PrintIntersectedNumbers(vector<int>& IntersectedNumbers) {
//	printf("Intersected Numbers :\n");
//
//	for (int& Number : IntersectedNumbers)
//	{
//		printf("%d  ", Number);
//	}
//
//
//}
//int MaxNumberInMatrix(int Matrix1[3][3], short rows, short columns) {
//	int CurrentNumber = Matrix1[0][0];
//	int MaxNumber = CurrentNumber;
//
//	for (short i = 0; i < rows; i++) {
//		for (short j = 0; j < columns; j++) {
//
//			CurrentNumber = Matrix1[i][j];
//
//			if (CurrentNumber > MaxNumber)
//				MaxNumber = CurrentNumber;
//		}
//	}
//	return MaxNumber;
//}
//
//int MinNumberInMatrix(int Matrix1[3][3], short rows, short columns) {
//	int CurrentNumber = Matrix1[0][0];
//	int MinNumber = CurrentNumber;
//
//	for (short i = 0; i < rows; i++) {
//		for (short j = 0; j < columns; j++) {
//			CurrentNumber = Matrix1[i][j];
//
//			if (CurrentNumber < MinNumber)
//				MinNumber = CurrentNumber;
//		}
//	}
//	return MinNumber;
//}
//
//int main() {
//	SeedRandomness();
//
//	int Matrix1[3][3];
//	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
//
//	printf("Matrix 1:\n");
//	PrintMatrix(Matrix1, 3, 3);
//
//	printf("Max Number :  %d \n", MaxNumberInMatrix(Matrix1, 3, 3));
//	printf("Min Number :  %d \n", MinNumberInMatrix(Matrix1, 3, 3));
//
//
//
//	return 0;
//}