#include <iostream>
#include<string>
#include<iomanip>
#include "../../Libs/MyLib.h"
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

int ColumnSum(int matrix[3][3], short rows, short columnNumber) {
	int sum = 0;
	for (int j = 0; j < rows; j++)
	{

		sum += matrix[j][columnNumber];

	};

	return sum;
}

void SumColumnsOfMatrix(int SumOfColumns[3], int matrix[3][3], short rows, short columns) {

	for (int i = 0; i < columns; i++) {


		SumOfColumns[i] = ColumnSum(matrix, rows, i);


	}

}

void PrintColumnsSum(int SumOfColumns[3], int length) {
	for (int i = 0; i < length; i++) {
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