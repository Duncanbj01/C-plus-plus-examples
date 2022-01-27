#include <iostream>
#include <cmath>
using namespace std; 

class Rectangle {
private: 

	double length, width; 
	char name; 

public: 

	Rectangle(double length, double width, char name) {
		this->length = length; 
		this->width = width;
		this->name = name;
		cout << "Rectangle " << name << " created." << endl; 
	}

	~Rectangle() {
		cout << "Rectangle " << name << " destroyed." << endl; 
	}

	double get_area() {
		return length * width; 
	}

	double get_perimeter() {
		return 2 * (length + width); 
	}
};