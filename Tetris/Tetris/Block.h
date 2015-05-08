#ifndef GAME_BLOCK_H
#define GAME_BLOCK_H

struct Position
{
	int X;
	int Y;

	Position(int _X, int _Y) : X(_X), Y(_Y) {}
	Position() : X(0), Y(0) {}
};

enum Type
{
	Empty,
	Filled
};

class Block
{
public:
	Position position;
	Type type;
private:
};

#endif