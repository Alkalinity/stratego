//  Normal_Piece.cpp
//  CS 120 A
//
//  Sam Pakulski 3/21
//

#include "Piece.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

Normal_Piece::Normal_Piece() : Piece() {
}
Normal_Piece::Normal_Piece(int i) {
	value = i;
}
Normal_Piece::~Normal_Piece() {
}
bool Normal_Piece::attack(Piece P) {
	if (value > P.getValue()) {
		return true;
	}
	else if (value < P.getValue()) {
		return false;
	}
	else if (value == P.getValue()) {
		return 0;
	}
}