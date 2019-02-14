#pragma once
#include "Polygonline.hpp"

Polygonline::LoopInLine::LoopInLine(const unsigned int i): DrawingObject::GraphException(i) {}

const unsigned int Polygonline::LoopInLine::getId()const {
	return id;
}
