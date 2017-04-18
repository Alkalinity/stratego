//  Piece.cpp
//  CS 120 A
//
//  Sam Pakulski 3/21
//

#include "Piece.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

Piece::Piece() {
	value = -1;
	red = true;
}
Piece::~Piece() {
}
int Piece::getValue() const {
	return value;
}
int Piece::getLocation() const {
	return location;
}
void Piece::setLocation(int i) {
	location = i;
}
bool Piece::getSide() {
	return red;
}
void Piece::setSide(bool s) {
	red = s;
}
bool Piece::attack(Piece p) {
	return false;
}
