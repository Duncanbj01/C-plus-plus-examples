#include <fstream>
#include <iostream>
#include "TicTacToe.h"
using namespace std;

void test(string filePath)
{ // complete this function
	ifstream reader(filePath, ios::in); 
	int numDim;
	reader >> numDim; 
	int numTurns; 
	reader >> numTurns; 


	int* choiceSequence = new int[numTurns];
	for (int i = 0; i < numTurns; i++)
	{
		reader >> choiceSequence[i];
		cout << choiceSequence[i] << " "; 
	}
	
	TicTacToe obj(numDim);
	obj.play(choiceSequence, numTurns);
}

int main() {
	string FOLDER_PATH = ""; // you may need to change this to the folder containing the files

	/*test(FOLDER_PATH + "3by3_XWins.txt");
	cout << endl;*/
	test(FOLDER_PATH + "3by3_XWins2.txt");
	cout << endl;
	/*test(FOLDER_PATH + "3by3_YWins.txt");
	cout << endl;
	test(FOLDER_PATH + "3by3_Draw.txt");
	cout << endl;
	test(FOLDER_PATH + "4by4_XWins.txt");
	cout << endl;
	test(FOLDER_PATH + "4by4_YWins.txt");
	cout << endl;
	test(FOLDER_PATH + "4by4_Draw.txt");*/
	return 1;
}