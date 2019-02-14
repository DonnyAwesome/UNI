//Bin Point.cpp

#include "Point.hpp"
#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

Point::Point(){
	setX(0);	
	setY(0);	
}

Point::Point(double tempX = 0, double tempY = 0){
	setX(tempX);	
	setY(tempY);	
}

Point::~Point(){
//	cout << "Deconstructor called" << endl;
}

void Point::setX(double tempX){
	x = tempX;	
}

void Point::setY(double tempY){
	y = tempY;
}

double Point::getX(){
	return x;
}

double Point::getY(){
	return y;
}

void Point::move(double aX, double aY){
	setX(x + aX);
	setY(y + aY);
}

void Point::print(bool end_line){			//Des bool ist nur für einen Zeilenvorschub
	cout << "(" << getX() << "," << getY() << ")";
	if (end_line){
		cout << endl;
	}
}




