#include "Point.hpp"
#include <vector>

using namespace std;

class Polygonline {
	// Private section
	vector<Point> Points;
	
	public:
		//public section
		Polygonline();
		Polygonline(Point p);
		Polygonline(int* points);
	
		Polygonline& addPoint(Point p);
		void appendPolygonline(Polygonline pl);
		void move(double m_x, double m_y);
		void print();
		
		Point getPoint(int tmp);
		int getSize();
};
