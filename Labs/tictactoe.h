#include <string>
#include <iostream>
using namespace std;

#ifndef TICTACTOE_H_
#define TICTACTOE_H_

class TicTacToe { // complete this class

public:

	char** M;
	int dim;
	char turn;

	TicTacToe(int d)
	{
		M = new char* [d];
		dim = d;
		for (int i = 0; i < d; i++) {
			M[i] = new char[d];
			for (int j = 0; j < d; j++) {
				M[i][j] = '\0';
			}
		}
		turn = 'X';
	}

	~TicTacToe()
	{
		for (int i = 0; i < dim; i++)
		{
			delete[] M[i];
		}
		delete[] M;
	}

private:
	bool checkWin(int r, int c)
	{
		int count = 0;
		// row check
		for (int i = 0; i < dim-1; i++)
		{

			if (M[r][i] == turn)
			{
				count++;
			}			
		}
		if (count == dim)
			return true;
		count = 0; 

		// col check
		for (int i = 0; i < c; i++)
		{
			if (M[i][c] == turn)
			{
				count++;
			}
		}
		if (count == dim)
			return true;
		count = 0;

		// digonal check
		for (int i = 0; i < r; i++)
		{
			if (M[i][i] == turn)
			{
				count++;
			}
		}
		if (count == dim)
			return true;
			count = 0;


		for (int i = 0; i < dim; i++)
		{
			if (M[dim-1-i][i] == turn)
			{
				count++;
			}
		}
		if (count == dim)
			return true;
		count = 0;

		cout << turn; 

		return false;
	}

	void printBoard()
	{
		for (int r = 0; r < dim; r++)
		{
			cout << "[";
			for (int c = 0; c < dim; c++)
			{
				
				if (M[r][c] == '\0')
				{
					cout << r * dim + c;
					cout << " ";
				}
				else
					cout << M[r][c] << " ";

				
			}
			cout << "]" << endl;
		}
		
	}
public:
	void play(int* choiceSequence, int numChoices)
	{

		cout << "*** Game Starts *** " << endl;
		printBoard();

		for (int i = 0; i < numChoices; i++)
		{
			cout << "*** Turn for " << turn << " chooses " << choiceSequence[i] << " ***";
			cout << endl; 

			if (choiceSequence[i] < 0 || choiceSequence[i] > dim * dim - 1)
			{
				cout << "Invalid choice! Must choose a number between 0 to " << dim * dim - 1;
				continue;
			}
			else
			{
				M[choiceSequence[i] / dim][choiceSequence[i] % dim];
			}

			if (M[choiceSequence[i] / dim][choiceSequence[i] % dim] != '\0')
			{
				cout << "This spot is already taken, try again.";
				continue;
			}

			M[choiceSequence[i] / dim][choiceSequence[i] % dim] = turn;
			printBoard();
			checkWin(choiceSequence[i] / dim, choiceSequence[i] % dim);

			if (checkWin(choiceSequence[i] / dim, choiceSequence[i] % dim) == true)
			{
				cout << turn << " has won the game!";
				break;
			}
			else
				turn;
			if (turn == 'X')
				turn = 'Y'; 
			else
				turn = 'X';			
		}
	 
		cout << "Game is a draw! Play again to keep the competition going!";
		system("pause");
		return;
	}
};

#endif /* TICTACTOE_H_ */
