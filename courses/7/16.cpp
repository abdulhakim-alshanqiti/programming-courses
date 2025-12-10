#include <iostream>
#include<string>
#include "../../libs/MyLib.h"
using namespace Input;
using namespace std;

void PrintMatrix(int matrix[8][8], short rows, short columns) {

	for (short i = 0; i < rows; i++) {

		for (short j = 0; j < columns; j++)
		{

			printf("%02d   ", matrix[i][j]);

		}
		printf("\n");
	}

}

void FillMatrixWithRandomNumbers(int matrix[8][8], short rows, short columns) {
	for (short i = 0; i < rows; i++) {

		for (short j = 0; j < columns; j++)
		{

			matrix[i][j] = RandomNumber(1, 10);

		}

	}
}
short NumberFrequncyInArray(int Matrix1[8][8], int NumberToCheck, short rows, short columns) {
	short counter = 0;
	for (short i = 0; i < rows; i++)
	{


		for (short j = 0; j < columns; j++) {

			if (Matrix1[i][j] == NumberToCheck)
			{

				counter++;

			}

		}
	}
	return counter;
}

bool IsASparceMatrix(int Matrix1[8][8], short rows, short columns) {
	float HalfMatrixSize = (rows * columns) / 2;
	return (NumberFrequncyInArray(Matrix1, 0, 8, 8) >= HalfMatrixSize);
}

void PrintIsASparceMatrix(int Matrix1[8][8], short rows, short columns) {
	if (IsASparceMatrix(Matrix1, 8, 8))
		printf("The Matrix is a Sparce Matrix");
	else
		printf("The Matrix is Not a Sparce Matrix");

}
int main() {
	SeedRandomness();

	int Matrix1[8][8] = {
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},

		{1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1}


	};


	printf("Matrix 1:\n");
	PrintMatrix(Matrix1, 8, 8);

	PrintIsASparceMatrix(Matrix1, 8, 8);


	return 0;
}