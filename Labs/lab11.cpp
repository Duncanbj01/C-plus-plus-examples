#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


enum ShapeType
{
	RECTANGLE,
	TRIANGLE 
};

enum ERRORCODE
{
	INVALID_TRIANGLE,
	INVALID_NUMBER_FORMAT,
	NEGATIVE_LENGTH
};

class Shape
{
protected:
	ShapeType type;
	string name;

	Shape(ShapeType type, string name)
	{
		this->type = type;
		this->name = name;
	}

public:
	double perimeter()
	{

	}
};

class Triangle : public Shape 
{
protected: 
	double a, b, c; 
public:
	
	Triangle(string name, double x, double y, double z) : Shape(ShapeType::TRIANGLE, name)
	{
		if (x < 0 || y < 0 || z < 0)
		{
			throw(ERRORCODE::NEGATIVE_LENGTH); 
		}
		if (x + y < z || x + z < y || y + z < x)
		{
			throw(ERRORCODE::INVALID_TRIANGLE); 
		}
		this->a = x; 
		this->b = y; 
		this->c = z; 		
	}
};

class Rectangle : public Shape
{
protected: 
	double length, width; 
public: 
	Rectangle(string name, double l, double w) : Shape(ShapeType::RECTANGLE, name)
	{
		if (l < 0 || w < 0)
		{
			throw(ERRORCODE::NEGATIVE_LENGTH); 
		}
		this->length = l; 
		this->width = w; 
	}

	double perimeter()
	{
		return length * width; 
	}
};

