#pragma once
#include "Rectangle.hpp"
#include <iostream>

using namespace std;

Rectangle::Rectangle(Point p1, Point p2): P1(p1), P2(p2){}

void Rectangle::print(bool b) const {
	cout << "[" << P1.toString() << ", " << P2.toString() << "]";
	if(b)
		cout << endl;
}

Rectangle::Rectangle(const string & s){
	string s1 = s.substr(s.find("),"));
	P1 = s;
	P2 = s1;
}