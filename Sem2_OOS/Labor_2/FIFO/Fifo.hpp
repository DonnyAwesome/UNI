//bin Aufgabe_2.hpp

#include <iostream>
#include <iomanip>

#ifndef SOMETHING_H
#define SOMETHING_H
using namespace std;

class FIFO {
	// Private section
	int maxSize;
	int number;
	char *ptr;
	int wPos;
	int rPos;
	
	
	public:
		// Public Declarations
		FIFO(int);
		~FIFO();
		
		int getWPos();
		int getRPos();
		bool isEmpty();
		bool isFull();
		int push(char c);
		char pop();
		
	
	
};

#endif
