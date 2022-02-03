#include <iostream>
#include "Circle.h"
using namespace std; 

int main()
{
	circle A(5, 7, 10, 'A');  
	cout << endl; 

	circle B(18,17,24,'B');
	cout << endl;

	circle C(25,30,5,'C');
	cout << endl;

	cout << "**********" << endl; 

	A.compare(&B); 
	cout << endl;

	C.compare(&A); 
	cout << endl;

	cout << "**********" << endl;

	cout << "A and B intersect? "; 
	cout << A.intersects(B); 
	cout << endl;

	cout << "A and C intersect? "; 
	cout << A.intersects(C);
	cout << endl;

	cout << "**********" << endl;

	cout << "Number of circles created = " << circle::numberOfCircles() << endl; 
	cout << "**********" << endl;
	return 0; 
}

