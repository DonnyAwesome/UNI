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

	//id zur�ckgeben
	unsigned int getId() const;

	//maxId zur�ckgeben
	static unsigned int getMaxId();

	//number zur�ckgeben
	static unsigned int getNumber();
};
