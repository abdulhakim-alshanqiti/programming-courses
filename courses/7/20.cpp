//#include <iostream>
//#include<string>
//#include "../../Libs/NumbersLib.h"
//#include <vector>
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
//
//
//bool IsMatrixPalindrome(int Matrix1[3][3], short rows, short columns) {
//	int CurrentNumber = 0;
//	int OppesiteNumber = 0;
//	for (short i = 0; i < rows; i++) {
//
//		for (short j = 0; j < columns / 2; j++) {
//			CurrentNumber = Matrix1[i][j];
//			OppesiteNumber = Matrix1[i][columns - 1 - j];
//
//			if (CurrentNumber != OppesiteNumber)
//				return false;
//		}
//
//	}
//	return true;
//}
//void PrintIsMatrixPalindrome(int Matrix1[3][3], short rows, short columns) {
//	if (IsMatrixPalindrome(Matrix1, rows, columns))
//		printf("Matrix Is Palindrome");
//	else
//		printf("Matrix Isn't Palindrome");
//
//}
//int main() {
//	SeedRandomness();
//
//	int Matrix1[3][3] = {
//		{1,2,1},
//		{5,5,5},
//		{7,3,7}
//	};
//
//
//	printf("Matrix 1:\n");
//	PrintMatrix(Matrix1, 3, 3);
//
//	PrintIsMatrixPalindrome(Matrix1, 3, 3);
//
//
//
//	return 0;
//}