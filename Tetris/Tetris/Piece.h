#ifndef GAME_PIECE_H
#define GAME_PIECE_H

#include "Block.h"

namespace Pieces
{
	enum Type
	{
		I,
		J,
		L,
		O,
		S,
		T,
		Z,
		Count = 3
	};
}

class Piece
{
public:
	Block blocks[4];
	Pieces::Type type;

	Piece();
	static int getNextPiece();

	Piece(int _type);
	~Piece();

	void Rotate();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
	void Drop();

private:





	Piece(const Piece& other);
	//Piece& operator=(const Piece& other);

};


#endif