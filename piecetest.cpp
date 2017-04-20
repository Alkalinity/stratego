/*

#include "piece.h"
#include <sstream>;

Piece::Piece() {
	value = 0;
}
Piece::Piece(int v, bool t) {
	red = t;
	if (red) {
		value = v;
	}
	else {
		value = v * (-1);
	}
}
void Piece::setString(string s) {
	test = s;
}
string Piece::toString() {
	stringstream s;
	s << "{" << value << "}";
	return s.str();
}
int Piece::getValue() {
	return value;
}
*/