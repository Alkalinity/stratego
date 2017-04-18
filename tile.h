//
//  CS 120 Stratego
//  tile.hpp
//

#ifndef tile_h
#define tile_h

#include "piece.h"
#include <string>
using namespace std;

struct color {
	double red;
	double green;
	double blue;
};

class Tile {
public:
	//constructor
	/**
	*Reruires: nothing
	*Moifies: nothing
	*Effects: creates a new tile, defaults to no occupant and a white background
	*/
	Tile();
	~Tile();
	//constructor
	/**
	*Reruires: a background color
	*Moifies: nothing
	*Effects: creates a new tile, sets the background to the given color and defaults to no occupant
	*/
	Tile(color c, bool a);
	//constructor
	/**
	*Reruires: a background color and an occupying peice
	*Moifies: nothing
	*Effects: creates a new tile, sets the background to the given color and sets the occupant
	*/
	Tile(color c, Piece p);
	/**
	*Reruires: a file name as a string
	*Moifies: nothing
	*Effects: sets the background image of a specific tile
	*/
	void setBackground(string s);
	/**
	*Reruires: a stratego piece
	*Moifies: nothing
	*Effects: sets the piece that the tile is occupied by
	*/
	void setOccupant(Piece p);
	/**
	*Reruires: nothing
	*Moifies: nothing
	*Effects: returns the piece occupying yhe tile
	*/
	Piece getOccupant();
	/**
	*Reruires: a background color
	*Moifies: nothing
	*Effects: sets the background of the tile to a solid color
	*/
	void setColor(color c);
	/**
	*Reruires: nothing
	*Moifies: nothing
	*Effects: returns whether or not the tile is accessible
	*/
	bool getAccessible();
	/**
	*Reruires: nothing
	*Moifies: nothing
	*Effects: returns whether or not the tile is occupied
	*/
	bool getOccupied();



private:
	color background;
	string imageFile;
	Piece occupant;
	bool occupied;
	bool accessible;
};
#endif