//bin Circle.hpp

#include <iostream>
#include "Point.hpp"
using namespace std;


class Circle {
	// Private section
	Point centre;
	double radius;
	
	public:
		// Public Declarations
	
	Circle();
	Circle(Point);	
	Circle(Point, double);
	
	void setCentre(Point tmp_centre);
	Point getCentre();
	void setRadius(double r);
	double getRadius();
	
	void move(double X, double Y);
	void print(bool = true);
		
};


