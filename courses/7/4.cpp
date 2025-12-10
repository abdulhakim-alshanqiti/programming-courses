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

int ColumnSum(int matrix[3][3], short columnNumber, short columns) {
	int sum = 0;
	for (int j = 0; j < columns; j++)
	{

		sum += matrix[j][columnNumber];

	};

	return sum;
}

void SumColumnsOfMatrix(int SumOfColumns[3], int matrix[3][3], short rows, short columns) {

	for (int i = 0; i < rows; i++) {


		SumOfColumns[i] = ColumnSum(matrix, i, columns);


	}

}

void PrintColumnsSum(int SumOfColumns[3], int rows) {
	for (int i = 0; i < rows; i++) {
		printf("The Sum Of Column [%d] = %d \n", i + 1, SumOfColumns[i]);
	}
}

int main() {
	SeedRandomness();

	int Matrix[3][3] = {};
	int SumOfColumns[3] = {};

	FillMatrixWithRandomNumbers(Matrix, 3, 3);

	Printl("Matrix 1: ");
	PrintMatrix(Matrix, 3, 3);

	SumColumnsOfMatrix(SumOfColumns, Matrix, 3, 3);
	PrintColumnsSum(SumOfColumns, 3);



	return 0;
}