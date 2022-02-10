#include <iostream>
#include <cmath>
#include <limits>
using namespace std;
#ifndef POINT_H_
#define POINT_H_

class Point {
public:
	double x, y;
	Point(double x, double y) {
		this->x = x;
		this->y = y;
	}
	~Point() {
		cout << "Point (" << x << "," << y << ") destroyed" << endl;
	}
	double distance(Point* arg) {
		double xDiff = x - arg->x;
		double yDiff = y - arg->y;
		return sqrt(xDiff * xDiff + yDiff * yDiff);
	}
};
#endif /* POINT_H_ */#pragma once
