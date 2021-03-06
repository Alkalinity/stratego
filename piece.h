#ifndef Piece_h
#define Piece_h

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <fstream>
using namespace std;

class Piece {
public:
	// default constructor
	/**
	* Requires: nothing
	* Modifies: All fields of Piece
	* Effects: Creates a piece, should never be used in program
	*/
	Piece();
	// destructor
	~Piece();

	// one RME for all getters and setters
	/**
	* Requires: nothing
	* Modifies: book fields
	* Effects: get and set values for
	*          the fields in book
	*/
	int getValue() const;
	int getLocation() const;
	void setLocation(int i);
	bool getSide();
	void setSide(bool s);
	virtual bool attack(Piece p);
protected:
	//fields
	int value;
	int location;
	bool red;
};

class Normal_Piece : public Piece {
public:
	Normal_Piece();

	Normal_Piece(int i, bool s);

	~Normal_Piece();

private:
	virtual bool attack(Piece P) override;
};

class Three : public Normal_Piece {
public:
	Three();
	Three(bool s);
	~Three();

private:
	virtual bool attack(Piece P) override;
};
class Spy : public Normal_Piece {
public:
	Spy();
	Spy(bool s);
	~Spy();
private:
	virtual bool attack(Piece P) override;
};

# endif /* Piece_h */