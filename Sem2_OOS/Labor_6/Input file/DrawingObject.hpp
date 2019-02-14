#pragma once
#include "ObjectCounter.hpp"

class DrawingObject: public ObjectCounter{
public:
	class GraphException {
	protected:
		const unsigned int id;
	public:
		GraphException(const unsigned int);
	};

	class IdTooHigh: public GraphException {
	public:
		IdTooHigh(const unsigned int);
		const unsigned int getId()const;
	};

	//Konstruktor
	DrawingObject();

	//Destruktor
	~DrawingObject();

	//Ausgabe aud konsole
	virtual void print(bool=false) const = 0;
	
	void check() const;

};