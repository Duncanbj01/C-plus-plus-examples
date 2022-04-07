#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Employee 
{
public:
	string employeeID;
	string name;
	string dateOfBirth;
	double salary;
	Employee(string employeeID, string name, string dateOfBirth, double salary)
	{
		this->employeeID = employeeID;
		this->name = name;
		this->dateOfBirth = dateOfBirth;
		this->salary = salary;
	}
	string toString() 
	{
		return employeeID + ", " + name + ", " + dateOfBirth + ", "	+ to_string(salary);
	}
};

class Bonus 
{
public:
	Employee* employee;
	double bonus;
	Bonus(Employee* employee, double bonus) 
	{
		this->employee = employee;
		this->bonus = bonus;
	}
};

class BonusCalculator 
{
private:
	static vector<string> split(string& str, string delimeter) 
	{
		// complete this function
		vector<string> tokens;
		string token;
		int startIndex = 0;
		int endIndex = str.find(delimeter);
		while (endIndex >= 0 && endIndex < str.length())
		{
			token = str.substr(startIndex, endIndex - startIndex);
			tokens.push_back(token);
			startIndex = endIndex + 1;
			endIndex = str.find(delimeter, startIndex);
		}
		token = str.substr(startIndex);
		tokens.push_back(token);
		return tokens;
	}
public:
	static vector<Bonus> computeBonus(string inputFilePath,	string errorFilePath) 
	{
		// complete this function
		
		ofstream writer(errorFilePath, ios::out); 
		writer << "ID, Name, Date of Birth, Salary" << endl; 
		vector<Bonus> arg; 

		ifstream reader(inputFilePath, ios::in); 
		while (getline(reader, inputFilePath))
		{
			vector<string> tokens = split(inputFilePath, ", ");

			Employee *e = new Employee (tokens.at(0), tokens.at(1), tokens.at(2), stod(tokens.at(3)));
			
			int stringyear; 
			stringyear = stoi(e->dateOfBirth.substr(e->dateOfBirth.length() - 4, 4));
			//int year = stoi(e.dateOfBirth.substr(e.dateOfBirth.length() - 4, 4)); 
			
			if (e->employeeID.length() != 11)
			{
				writer << e->toString() << endl; 
			}
			else if (stringyear >= 1990)
			{
				Bonus tempBonus(e, e->salary * 0.04); 
				arg.push_back(tempBonus);
			}
			else if (stringyear < 1990 && stringyear >= 1980)
			{
				Bonus tempBonus(e, e->salary * 0.06);
				arg.push_back(tempBonus);
			}
			else if (stringyear < 1980 && stringyear >= 1970)
			{
				Bonus tempBonus(e, e->salary * 0.08);
				arg.push_back(tempBonus); 
			}
			else if (stringyear < 1970)
			{
				Bonus tempBonus(e, e->salary * 0.1);
				arg.push_back(tempBonus); 
			}
			
		}
		reader.close(); 
		writer.close(); 
		
		

		return arg; 
	}
};
int main() {
	vector<Bonus> bonuses = BonusCalculator::computeBonus("employee.csv","error.csv");
	for (int i = 0; i < bonuses.size(); i++)
		cout << bonuses[i].employee->toString() << ", " << bonuses[i].bonus	<< endl << endl;
}
