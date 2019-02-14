#include <iostream>
#include "string.h"
#include "Point.hpp"
#include "MyString.hpp"

using namespace std;

string removeCharFromString(string &str, char charToRemove) {					//Hilfsfunktion
	string output;
	output.reserve(str.size()); // optional, avoids buffer reallocations in the loop
	for(int i = 0; i < str.size(); ++i)					//For Schleife brauch ich immer um den String ab zu arbeiten
		if(str[i] != charToRemove) output += str[i];		//Wenn char nicht charToRemove ist, dann putte das char in output
		
	return output;		//returned String , der nicht mehr das unerwünschte Zeichen enthält
}

Point::Point(){
	setX(0);	
	setY(0);	
}

Point::Point(string str){						//Konstruktor mit String als Parameter

	str = removeCharFromString(str, ' ');		//entferne sämtliche Leerzeichen
	int end_pos = 1;
	double x, y = 0;
	string cutter = ",";
	str = removeCharFromString(str, '(');		//entferne sämtliche Klammern auf
	
	while (str.at(end_pos) != ')'){				//ermittle Ende des ersten Strings, damit ich mich um restliche Zeichenketten nach dem ) nicht sorgen muss
		end_pos++;
	}
	
	string pt;
	for(int i = 0; i < end_pos; ++i){
	pt += str[i];
	}
//	cout << str << endl;
	pt = removeCharFromString(pt, ')');			//entferne sämtliche Klammern zu
//	cout << str << endl;
//	cout << pt << endl;
	
	int pos = 0;
	string token;
	while (pos = pt.find(cutter) != string::npos) {
	    token = pt.substr(0, pos);
	    //cout << token;
		x = atof(pt.c_str());
	    pt.erase(0, pos + cutter.length());
	}
	//cout << clean_line << endl;	
	y = atof(pt.c_str());
	//cout << x << endl << y << endl;	
	setX(x);	
	setY(y);	
}

Point::Point(double tmp_x = 0, double tmp_y = 0){
	setX(tmp_x);	
	setY(tmp_y);	
}

void Point::setX(double tmp_x){
	x = tmp_x;	
}

void Point::setY(double tmp_y){
	y = tmp_y;
}

double Point::getX(){
	return x;
}

double Point::getY(){
	return y;
}

void Point::move(double m_x, double m_y){
	setX(x + m_x);
	setY(y + m_y);
}

string Point::toString(){
	string res;
	res.append("(");
	res.append(to_string(getX())); //to_string konvertiert double X zu string
	res.append(", ");
	res.append(to_string(getY()));	
	res.append(")");
	return res;
}

ostream& operator << (ostream & s, Point& p){
	return s << "(" << p.getX() << ", " << p.getY() << ")" << endl;
}

istream& operator >> (istream & in, Point& p){
	//str.read(in);
	return in;
}
