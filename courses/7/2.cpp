#include <iostream>
#include<string>
#include<iomanip>
#include "../../libs/MyLib.h"
using namespace Input;
using namespace Output;
using namespace std;

void PrintMatrix(int matrix[3][3], short rows, short columns) {

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < columns; j++)
		{
			cout << setw(3) << matrix[i][j] << "   ";

		}
		Printl();
	}

}
void FillMatrixWithRandomNumbers(int matrix[3][3], short rows, short columns) {
	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < columns; j++)
		{

			matrix[i][j] = RandomNumber(1, 100);

		}

	}
}

int RowSum(int matrix[3][3], short rowNumber, short columns) {
	int sum = 0;
	for (int j = 0; j < columns; j++)
	{

		sum += matrix[rowNumber][j];

	}
	return sum;
}

void SumRowsOfMatrix(int matrix[3][3], short rows, short columns) {

	for (int i = 0; i < rows; i++) {

		printf("The Sum Of Row [%d] = %d \n", i + 1, RowSum(matrix, i, columns));

	}
}

int main() {
	SeedRandomness();

	int Matrix[3][3] = {};

	FillMatrixWithRandomNumbers(Matrix, 3, 3);

	Printl("Matrix 1: ");
	PrintMatrix(Matrix, 3, 3);

	SumRowsOfMatrix(Matrix, 3, 3);


	return 0;
}