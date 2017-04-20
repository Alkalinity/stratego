//
//  CS 120 Stratego
//  tile.cpp
//

#include "tile.h"

Tile::Tile() {
	background.red = background.green = background.blue = 0;
	occupied = false;
	accessible = true;
}
Tile::~Tile() {

}
Tile::Tile(color c, bool a) {
	background = c; 
	accessible = a;
	occupied = false;
}
Tile::Tile(Piece p) {
	occupant = p;
	occupied = true;
	accessible = true;
}
Tile::Tile(color c, Piece p){
	background = c;
	occupied = true;
	occupant = p;
	accessible = true;
}
void Tile::setBackground(string s) {
	imageFile = s;
}
void Tile::setOccupant(Piece p) {
	if (p.getValue() == -1)
	{
		occupied = false;
	}
	occupant = p;
}
Piece Tile::getOccupant() {
	return occupant;
}
void Tile::setColor(color c) {
	background = c;
}
bool Tile::getAccessible() {
	return accessible;
}
bool Tile::getOccupied() {
	return occupied;
}

