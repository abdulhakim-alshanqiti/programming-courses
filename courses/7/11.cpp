#include <iostream>
#include<string>
#include<iomanip>
#include "../../libs/MyLib.h"
using namespace Input;
using namespace Output;
using namespace std;

void PrintMatrix(int matrix[3][3], short rows, short columns) {

	for (short i = 0; i < rows; i++) {

		for (short j = 0; j < columns; j++)
		{

			printf("%02d   ", matrix[i][j]);

		}
		Printl();
	}

}
void FillMatrixWithOrderedNumbers(int matrix[3][3], short rows, short columns) {
	short count = 0;
	for (short i = 0; i < rows; i++) {

		for (short j = 0; j < columns; j++)
		{
			count++;

			matrix[i][j] = count;

		}

	}
}


void FillMatrixWithRandomNumbers(int matrix[3][3], short rows, short columns) {
	for (short i = 0; i < rows; i++) {

		for (short j = 0; j < columns; j++)
		{

			matrix[i][j] = RandomNumber(1, 5);

		}

	}
}
void PrintMiddleRowOfMatrix(int matrix[3][3], short rows, short columns) {
	short middleRow = rows / 2;



	for (short i = 0; i < columns; i++)
	{



		printf("%02d   ", matrix[middleRow][i]);
	}

	Printl();


}
int SumOfMatrix(int matrix[3][3], short rows, short columns) {


	int sum = 0;

	for (short i = 0; i < rows; i++)
	{


		for (short j = 0; j < columns; j++) {
			sum += matrix[i][j];

		}

	}
	return sum;
}
bool IsTheMatrixesEqual(int Matrix1[3][3], int Matrix2[3][3], short rows, short columns) {
	return (SumOfMatrix(Matrix1, 3, 3) == SumOfMatrix(Matrix2, 3, 3));


}
void PrintTheResult(bool Equal) {
	if (Equal)
		Printl("Yes The Matrixes Are Equal");
	else
		Printl("No The Matrixes Aren't Equal");
}
int main() {
	SeedRandomness();

	int Matrix1[3][3] = {	};
	int Matrix2[3][3] = {	};

	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	Printl("Matrix 1:");
	PrintMatrix(Matrix1, 3, 3);


	FillMatrixWithRandomNumbers(Matrix2, 3, 3);
	Printl("Matrix 2:");
	PrintMatrix(Matrix2, 3, 3);


	PrintTheResult(IsTheMatrixesEqual(Matrix1, Matrix2, 3, 3));





	return 0;
}