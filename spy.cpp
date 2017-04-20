//  Spy.cpp
//  CS 120 A
//
//  Sam Pakulski 3/21
//

#include "Piece.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
Spy::Spy() {

}
Spy::Spy(bool s) : Normal_Piece() {
	value = 1;
	red = s;
}
Spy::~Spy() {
}
bool Spy::attack(Piece P) {
	if (P.getValue() == 10) {
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