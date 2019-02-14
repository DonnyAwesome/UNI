#include <iostream>
#include "MyData.hpp"
#pragma once

using namespace std;

class MyListElement;

class MyList
{
public: 
	MyList  ();
	MyList	(const MyList &);
	~MyList ();
	
	void         clear(); // Liste wird geleert
	unsigned int size(); // Anzahl der Elemente werden zur�ck geliefert
	bool		 empty(); // pr�ft, ob Liste leer ist
	MyData &	 at(unsigned int) const;
	void		 push_back(const MyData &); // Ein Element wird geh�ngt
	void		 pop_back(); // Element wird gel�scht
	MyData&		 front() const; // erste Element wird zur�ck geliefert
	MyData&		 back()  const; // letzte Element wird zur�ck geliefert
	void		 print();
	MyList&		 operator= (const MyList &);
	MyList&		 operator+ (const MyList &);

private:
	MyListElement * first;
	MyListElement * last;
	unsigned int Size;
};

class MyListElement
{
public:
	friend MyList;

	MyListElement(MyData * data) : data(data) {}

	~MyListElement()
	{
		delete data;
		delete next;
	}

private:
	MyListElement * next;
	MyData		  * data;
};
