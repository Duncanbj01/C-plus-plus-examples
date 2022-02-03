#include <iostream>
#include <cmath>
using namespace std; 

class circle {

private: 
	double x, y, radius; 
	char name; 

	static int counter; 

public: 

	void print() {
		cout << "(" << x << ", " << y << ", " << radius << ", " << name << ")"; 
	}

	circle(double a, double b, double c, char d) {
		x = a; 
		y = b; 
		radius = c; 
		name = d; 
		counter++; 
		cout << "Circle "; 
		print();
	}

	~circle() {
		cout << "Circle "; 
		print(); 
		cout << " destroyed." << endl; 
	}

	void compare(circle *arg1) {
		if (arg1->radius > radius)
		{
			cout << "Circle with larger area: ";
			arg1->print();
		}
		else
			print(); 

	}

	bool intersects(circle &arg1){
		if (arg1.radius + radius > sqrt((arg1.x - x) * (arg1.x - x) + (arg1.y - y) * (arg1.y - y)))
			return true;
		else
			return false; 
	}

	static int numberOfCircles() {
		return counter; 
	}
};

int circle::counter = 0;
