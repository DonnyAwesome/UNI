#pragma once
#include "DrawingObject.hpp"

DrawingObject::IdTooHigh::IdTooHigh(const unsigned int i): DrawingObject::GraphException(i) {}

const unsigned int DrawingObject::IdTooHigh::getId() const {
	return id;
}