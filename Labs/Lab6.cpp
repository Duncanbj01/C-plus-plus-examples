#include <iostream>
#include <fstream>
using namespace std;

class Lab6 {

public:

	static void shiftColumnsRight(int**M, int numRows, int numCols) {
		
		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0; j < numCols; j++) {
				cout << M[i][j] << " ";
			}
			cout << endl; 
		}
			for (int i = 0; i < numRows; i++) // goes over the rows. 
			{
				for (int j = numCols - 2; j >= 0; j--) // goes over the columns. 
				{

					int temp = M[i][j];
					M[i][j] = M[i][j + 1];
					M[i][j + 1] = temp;	
				}			
			}
			cout << endl;
			for (int i = 0; i < numRows; i++)
			{
				for (int j = 0; j < numCols; j++) {
					cout << M[i][j] << " ";
				}
				cout << endl;
			}
		}
	

	static int sumDiagonals(int** M, int numRows)
	{
		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0; j < numRows; j++) {
				cout << M[i][j] << " ";
			}
			cout << endl;
		}

		int sum = 0;
		for (int i = 0; i < numRows; i++) 
		{
			sum += M[numRows - 1 - i][i];
			sum += M[i][i];			
		}

		if (numRows % 2 == 1)
		{
			sum -= M[numRows / 2][numRows / 2];
		}
		return sum;
	}

	static int findMinimumInJaggedArray()
	{
		int numR;
		ifstream reader("jagged.txt", ios::in);
	

		reader >> numR;

		int** arr = new int* [numR]; // creating an array of integer pointers of length numR. 

		int* numC = new int[numR];

		for (int r = 0; r < numR; r++)
		{
			 
			reader >> numC[r];


			arr[r] = new int[numC[r]];  // allocating numC cells for row r
			for (int c = 0; c < numC[r]; c++)
			{
				reader >> arr[r][c]; 
			}		 
		}
		
		for (int r = 0; r < numR; r++)
		{
			for (int c = 0; c < numC[r]; c++)
			{

				cout << arr[r][c] << " ";
			}
			cout << endl;
		}

		int min = 2147483647;
		for (int r = 0; r < numR; r++)
		{
			for (int c = 0; c < numC[r]; c++)
			{

				if (arr[r][c] < min)
				{
					min = arr[r][c]; 
				}
			}			
		}
		return min; 
	}


	
	// all functions go here
};

int main() {
	int shiftMatrix_row0[] = { 1, 2, 3, 4, 5 };
	int shiftMatrix_row1[] = { 6, 7, 8, 9, 10 };
	int shiftMatrix_row2[] = { 11, 12, 13, 14, 15 };
	int shiftMatrix_row3[] = { 16, 17, 18, 19, 20 };

	int* shiftMatrix[] = { shiftMatrix_row0, shiftMatrix_row1, shiftMatrix_row2,
			shiftMatrix_row3 };
	Lab6::shiftColumnsRight(shiftMatrix, 4, 5);

	cout << endl << "**********************" << endl << endl;

	int diag5_row0[] = { 1, 2, 3, 4, 5 };
	int diag5_row1[] = { 6, 7, 8, 9, 10 };
	int diag5_row2[] = { 11, 12, 13, 14, 15 };
	int diag5_row3[] = { 16, 17, 18, 19, 20 };
	int diag5_row4[] = { 21, 22, 23, 24, 25 };

	int* diagonal5[] = { diag5_row0, diag5_row1, diag5_row2, diag5_row3,
			diag5_row4 };

	int sum = Lab6::sumDiagonals(diagonal5, 5);
	cout << "The sum is : " << sum << endl << endl;

	int diag4_row0[] = { 1, 2, 3, 4 };
	int diag4_row1[] = { 5, 6, 7, 8 };
	int diag4_row2[] = { 9, 10, 11, 12 };
	int diag4_row3[] = { 13, 14, 15, 16 };

	int* diagonal4[] = { diag4_row0, diag4_row1, diag4_row2, diag4_row3 };
	sum = Lab6::sumDiagonals(diagonal4, 4);
	cout << "The sum is : " << sum << endl;

	cout << endl << "**********************" << endl << endl;

	int min = Lab6::findMinimumInJaggedArray();
	cout << endl << "The minimum is " << min;
}

