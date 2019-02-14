//bin Point.hpp
#pragma once
#include <iostream>

class Point {
	// Private section
	double x;				//Koordinate x des Punktes
	double y;				//Koordinate y
	
	public:
		// Public Declarations
		Point();
		Point(double, double);
		~Point();
	
	void setX(double);
	void setY(double);
	double getX();
	double getY();

	void move(double, double);
	void print(bool = true);
		
		
		
};


