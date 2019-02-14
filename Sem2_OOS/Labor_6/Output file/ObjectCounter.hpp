#pragma once

extern bool debugConstructor;

class ObjectCounter {
	const unsigned int id;
	static unsigned int number;
	static unsigned int maxId;

public:
	//Konstruktor
	ObjectCounter();

	//Destruktor
	~ObjectCounter();

	//id zurückgeben
	unsigned int getId() const;

	//maxId zurückgeben
	static unsigned int getMaxId();

	//number zurückgeben
	static unsigned int getNumber();
};
