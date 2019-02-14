//bin Circle.cpp

#include"Circle.hpp"
#include <iostream>

Circle::Circle(){
	Point p;
	setCentre(p);
	setRadius(0);	
}

Circle::Circle(Point c){
	setCentre(c);
	setRadius(0);	
}

Circle::Circle(Point c, double r){
	setCentre(c);
	setRadius(r);
}

void Circle::setCentre(Point tmpCentre){
	centre = tmpCentre;
}

void Circle::setRadius(double r){
	radius = r;
}

Point Circle::getCentre(){
	return centre;
}

double Circle::getRadius(){
	return radius;
}

void Circle::move(double X, double Y){
	centre.move(X, Y);
}

void Circle::print(bool end_line){
	cout << "<(" << centre.getX() << "," << centre.getY() << "), " << radius << ">";
	if (end_line){
		cout << endl;
	}
}

