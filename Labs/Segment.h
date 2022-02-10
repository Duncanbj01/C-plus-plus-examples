#include <iostream>
#include <cmath>
#include <limits>
#include "Point.h"
using namespace std;

class Segment {
private:
	Point* start;
	Point* end;
	char name;

public:
	Segment(Point* x, Point* y, char z)
	{
		start = x;
		end = y;
		name = z;
	}

	~Segment() {
		start->~Point();
		end->~Point();
	}

	double length() {
		return start->distance(end); 
	}

	double slope() {
		if (start->x == end->x)
			return numeric_limits<double>::infinity(); 
		else
			return (start->y - end->y) / (start->x - end->x); 
	}

	bool isParallel(Segment* arg) {
		if (slope() == arg->slope()) {
			cout << "are parallel";
			return true;
		}
		else
			cout << "are not parallel"; 
			return false;
	}
};
