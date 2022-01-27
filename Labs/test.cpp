#include <iostream>
#include <cmath>
#include "Rectangle.h"
using namespace std; 

int main()
{
	Rectangle A(15.7, 10.0, 'A'); 
	Rectangle B(5.0, 100.0, 'B'); 
	Rectangle C(30.1, 5.2, 'C'); 
	Rectangle D(20.5, 5.6, 'D'); 

	cout << "Area of Rectangle A = " <<  A.get_area() << endl;
}