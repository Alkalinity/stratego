//  Three.cpp
//  CS 120 A
//
//  Sam Pakulski 3/21
//

#include "Piece.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
Three::Three() {

}
Three::Three(bool s) : Normal_Piece() {
	value = 3;
	red = s;
}
Three::~Three() {
}
bool Three::attack(Piece P) {
	if (P.getValue() == 99) {
		return true;
	}
	else if (value > P.getValue()) {
		return true;
	}
	else if (value < P.getValue()) {
		return false;
	}
	else if (value == P.getValue()) {
		return 0;
	}
}