#include <iostream>
#include <cmath>
#include <limits>
#include "Segment.h"
using namespace std;

int main() {
	Point* w = new Point(5, 9); 
	Point* x = new Point(8, 15); 
	Point* y = new Point(11, 25); 
	Point* z = new Point(5, 7); 

	Segment A(z, w, 'A'); 
	Segment B(z, x, 'B'); 
	Segment C(w, y, 'C'); 

	cout << "Length of segment A is " << A.length(); 
	cout << endl; 
	cout << "Length of segment B is " << B.length();
	cout << endl;
	cout << "Length of segment C is " << C.length();
	cout << endl;
	cout << endl;

	cout << "Slope of segment A is " << A.slope(); 
	cout << endl;
	cout << "Slope of segment B is " << B.slope();
	cout << endl;
	cout << "Slope of segment C is " << C.slope();
	cout << endl;
	cout << endl;

	cout << "Segments B and C ";
	 B.isParallel(&C); 
	cout << endl;
	cout << "Segments A and B "; 
	 A.isParallel(&B);
	cout << endl;


		
}