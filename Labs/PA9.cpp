#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

enum ShapeType
{
	CUBOID = 0,
	CYLINDER = 1, 
	SPHERE = 2
};

enum ErrorType
{
	INVALID_LENGTH_ARGUMENT = 0, 
	NOT_ENOUGH_ARGUMENTS = 1, 
	NOT_A_NUMBER = 2, 
	INVALID_SHAPE_TYPE = 3
};

class AbstractShape
{ 
protected: 
	ShapeType shapeType; 
	string shapeName; 
	
	AbstractShape(string& name, ShapeType type)
	{
		this->shapeName = name;
		this->shapeType = type;
	}
public: 
	virtual ~AbstractShape()
	{
	}

	virtual double area()
	{
	}
	virtual double volume()
	{
	}

	string name()
	{
		return shapeName; 
	}

	ShapeType type()
	{
		return shapeType; 
	}

	string toString() {
		return shapeName + ", AREA: " + to_string(area()) + ", VOLUME: "
			+ to_string(volume());
	}
};

class Cuboid : public AbstractShape
{
protected: 
	double length, width, height; 

public:
	Cuboid(double length, double width, double height, string name) : AbstractShape(name, ShapeType::CUBOID)
	{
		if (length <= 0 || width <= 0 || height <= 0)
			throw(ErrorType::INVALID_LENGTH_ARGUMENT); 
			this->length = length; 
			this->width = width;
			this->height = height;
	}
	virtual ~Cuboid()
	{

	}

};