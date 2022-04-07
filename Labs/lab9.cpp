#include <string>
#include <cmath>
#include <iostream>
using namespace std;
// all classes go here
// you can also use separate .h files for each of the classes if you want to, but remember to include them here

class Shape 
{
protected: 
	string name; 

	Shape(string nameArg)
	{
		name = nameArg; 
	}
public: 

	string getName()
	{
		return name; 
	}

	double virtual area()
	{
		return -1; 
	}

	double virtual perimeter()
	{
		return -1; 
	}
};

class Rectangle : public Shape
{
private: 
	double length, width; 

public: 
	Rectangle(double l, double w, string name): Shape(name)
	{
		length= l; 
		width = w; 		
	}

	double perimeter()
	{
		return 2 * (length + width); 
	}
	double area()
	{
		return length * width; 
	}
};

class Square : public Rectangle
{
public: 
	Square(double side, string name) : Rectangle(side, side, name)
	{
		
	}
};

class Triangle : public Shape
{
	double a, b, c; 

public: 
	Triangle(double a, double b, double c, string name) : Shape(name)
	{	 
		this->a = a; 
		this->b = b; 
		this->c = c; 
	}
	bool isValid() {
		if (a + b > c && a + c > b && b + c > a)
		{
			return true;
		}
		else
			return false; 
	}
	double perimeter()
	{
		if (isValid() == false)
			return -1;
		else
			return a + b + c; 
	}

	double area()
	{
		double s = perimeter() / 2; 
		if (isValid() == false)
			return -1;
		else
			return sqrt(s * (s - a) * (s - b) * (s - c)); 
	}
};

class ShapePrinter 
{
public: 
	static void print(Shape* shape)
	{
		cout << "Name is: " << shape->getName() << endl;
		cout << "Perimeter is: " << shape->perimeter() << endl;
		cout << "Area is: " << shape->area() << endl;
	}
};


int main() {
	cout << "***\n" << endl;
	string rect_1 = "Rectangle1";
	Rectangle* rect = new Rectangle(5, 12, rect_1);
	ShapePrinter::print(rect);
	cout << "\n***\n" << endl;
	string square_1 = "Square1";
	Square* square = new Square(5, square_1);
	ShapePrinter::print(square);
	cout << "\n***\n" << endl;
	string triangle_1 = "Triangle1";
	Triangle* tri1 = new Triangle(5, 6, 16, triangle_1);
	ShapePrinter::print(tri1);
	cout << "\n***\n" << endl;
	string triangle_2 = "Triangle2";
	Triangle* tri2 = new Triangle(6, 16, 5, triangle_2);
	ShapePrinter::print(tri2);
	cout << "\n***\n" << endl;
	string triangle_3 = "Triangle3";
	Triangle* tri3 = new Triangle(16, 5, 6, triangle_3);
	ShapePrinter::print(tri3);
	cout << "\n***\n" << endl;
	string triangle_4 = "Triangle4";
	Triangle* tri4 = new Triangle(5, 5, 5, triangle_4);
	ShapePrinter::print(tri4);
	cout << "\n***\n" << endl;
	string triangle_5 = "Triangle5";
	Triangle* tri5 = new Triangle(3, 5, 4, triangle_5);
	ShapePrinter::print(tri5);
	cout << "\n***\n" << endl;
	string triangle_6 = "Triangle6";
	Triangle* tri6 = new Triangle(4, 6, 4, triangle_6);
	ShapePrinter::print(tri6);
	delete rect;
	delete square;
	delete tri1;
	delete tri2;
	delete tri3;
	delete tri4;
	delete tri5;
	delete tri6;
	return 1;
}