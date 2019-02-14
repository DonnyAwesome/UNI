#pragma once 

class Point{
	
	private:
		
	double x;
	double y;
	
public:
	
	Point(double tmp_x, double tmp_y);
	Point();
	
	void setX(double tmp_x);
	void setY(double tmp_y);
	double getX();
	double getY();

	void move(double m_x, double m_y);
	void print(bool = true);
	
	
};
