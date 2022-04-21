#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum ErrorCode
{
	NEGATIVE_NUMBER = 0,
	NOT_A_NUMBER_X = 1,
	NOT_A_NUMBER_Y = 2
};

class Point
{
public:
	double x, y;
	char name;

	Point(double x, double y, char name)
	{
		if (x < 0 || y < 0)
			throw(ErrorCode::NEGATIVE_NUMBER);
		this->x = x;
		this->y = y;
		this->name = name;
	}

	string toString()
	{
		return "(" + to_string(x) + "," + to_string(y) + "," + name + ")";
	}

};

class fileReader
{
protected:
	static vector <string> split(string& str, string delimeter)
	{
		vector<string> tokens;
		string token;
		int startIndex = 0;
		int endIndex = str.find(delimeter);
		while (endIndex >= 0 && endIndex < str.length())
		{
			token = str.substr(startIndex, endIndex - startIndex);
			tokens.push_back(token);
			startIndex = endIndex + delimeter.length();
			endIndex = str.find(delimeter, startIndex);
		}

		token = str.substr(startIndex);
		tokens.push_back(token);
		return tokens;
	}

public: 
	static bool isNumber(string &str)
	{
		int countDots = 0;
		int countNeg = 0;
		string digits = "0123456789";
		for (int i = 0; i < str.length(); i++)
		{
			char c = str.at(i);
			int index = digits.find(c);

			if (c == '.')
			{
				countDots++;
			}
			else if (c == '-')
			{
				countNeg++;
			}
			else
			{
				int index = digits.find(c);
				if (index < 0 || index >= digits.length())
					return false;
			}
		}
		if (countNeg > 1)
		{
			return false;
		}
		else
		{
			return true;
		}

		return countDots <= 1;
	}

public:

	static void parseFile()
	{
		ifstream reader("exceptionhandling.txt", ios::in);
		ofstream errorwriter("errorpoints.txt", ios::out);
		ofstream validwriter("validpoints.txt", ios::out);

		string line;
		while (getline(reader, line))
		{
			vector<string> tokens = split(line, " ");
			string temp; 
			temp = tokens.at(2); 
			try
			{
				char name = tokens.at(0).at(0);
				if (!isNumber(tokens.at(1)))
				{
					throw(ErrorCode::NOT_A_NUMBER_X);
				}
				if (!isNumber(tokens.at(2)))
				{
					throw(ErrorCode::NOT_A_NUMBER_Y);
				}
				double x = stod(tokens.at(1));
				double y = stod(tokens.at(2));

				Point p(x, y, name);
				validwriter << p.toString() << endl;
			}
			catch (int arg)
			{
				if (arg == ErrorCode::NEGATIVE_NUMBER)
				{
					errorwriter << "Negative number exception: ";
				}
				else if (arg == ErrorCode::NOT_A_NUMBER_X)
				{
					errorwriter << "x is not a number: ";
				}
				else
				{
					arg == ErrorCode::NOT_A_NUMBER_Y;
				}
				errorwriter << tokens.at(0) << " " << tokens.at(1) << " " << tokens.at(2) << endl;
			}
		}
		reader.close();
		errorwriter.close();
		validwriter.close();

	}
};

int main()
{
	string temp = "7.3"; 
	cout << fileReader::isNumber(temp);
	fileReader::parseFile();
	return 1;
}