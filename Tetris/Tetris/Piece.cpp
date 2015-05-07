#include <stdlib.h>
#include "Piece.h"

Piece::Piece(int _type )
{
	type = (Pieces::Type)_type;

	switch (_type)
	{
	case Pieces::I:
		blocks[0].position = Position(5, 0);
		blocks[1].position = Position(5, 1);
		blocks[2].position = Position(5, 2);
		blocks[3].position = Position(5, 3);
		blocks[0].type = Type::Filled;
		blocks[1].type = Type::Filled;
		blocks[2].type = Type::Filled;
		blocks[3].type = Type::Filled;
		break;
	case Pieces::J:
		blocks[0].position = Position(5, 0);
		blocks[1].position = Position(5, 1);
		blocks[2].position = Position(5, 2);
		blocks[3].position = Position(4, 2);
		blocks[0].type = Type::Filled;
		blocks[1].type = Type::Filled;
		blocks[2].type = Type::Filled;
		blocks[3].type = Type::Filled;
		break;
	case Pieces::L:
		blocks[0].position = Position(5, 2);//center
		blocks[1].position = Position(5, 0);
		blocks[2].position = Position(5, 1);
		blocks[3].position = Position(6, 2);
		blocks[0].type = Type::Filled;
		blocks[1].type = Type::Filled;
		blocks[2].type = Type::Filled;
		blocks[3].type = Type::Filled;
		break;
	case Pieces::O:
		break;
	case Pieces::S:
		break;
	case Pieces::T:
		break;
	case Pieces::Z:
		break;
	default:
		break;
	}

}

Piece::Piece()
{

}

Piece::~Piece()
{

}

int
Piece::getNextPiece()
{
	return (rand() % Pieces::Count);
}

void
Piece::MoveDown()
{
	for (int i = 0; i < 4; i++)
	{
		blocks[i].position.Y++;
	}
}

void
Piece::MoveLeft()
{
	for (int i = 0; i < 4; i++)
	{
		blocks[i].position.X--;
	}
}

void
Piece::MoveRight()
{
	for (int i = 0; i < 4; i++)
	{
		blocks[i].position.X++;
	}
}

void
Piece::Rotate()
{
	int newX;
	int newY;
	int temp;

	for (int  i = 0; i < 3; i++)
	{
		newX = blocks[i+1].position.X - blocks[0].position.X;
		newY = blocks[i+1].position.Y - blocks[0].position.Y;

		temp = newX;
		newX = newY;
		newY = -temp;

		newX += blocks[0].position.X;
		newY += blocks[0].position.Y;

		blocks[i+1].position.X = newX;
		blocks[i+1].position.Y = newY;
	}
}