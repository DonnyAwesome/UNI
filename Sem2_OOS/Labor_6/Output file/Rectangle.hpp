#pragma once
#include "Point.hpp"
#include "OneDimObject.hpp"
#include <string>
using namespace std;

class Rectangle: public OneDimObject{
	Point P1;
	Point P2;
public:
	Rectangle(Point p1 = "(0,0)", Point p2 = "0,0");
	Rectangle(const string &);
	virtual void print (bool=true) const;
};
