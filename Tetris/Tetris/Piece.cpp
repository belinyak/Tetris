#include <stdlib.h>
#include "Piece.h"
#include "Board.h"

extern Board board;

Piece::Piece(int _type )
{
	type = (Pieces::Type)_type;

	switch (_type)
	{
	case Pieces::I:
		blocks[1].position = Position(5, 1);//center
		blocks[0].position = Position(5, 0);
		blocks[2].position = Position(5, 2);
		blocks[3].position = Position(5, 3);
		break;
	case Pieces::J:
		blocks[2].position = Position(5, 2);//center
		blocks[0].position = Position(5, 0);
		blocks[1].position = Position(5, 1);
		blocks[3].position = Position(4, 2);
		break;
	case Pieces::L:
		blocks[0].position = Position(5, 2);//center
		blocks[1].position = Position(5, 0);
		blocks[2].position = Position(5, 1);
		blocks[3].position = Position(6, 2);
		break;
	case Pieces::O:
		blocks[1].position = Position(5, 1);//center
		blocks[0].position = Position(5, 0);
		blocks[2].position = Position(6, 0);
		blocks[3].position = Position(6, 1);
		break;
	case Pieces::S:
		blocks[1].position = Position(5, 1);//center
		blocks[0].position = Position(6, 0);
		blocks[2].position = Position(5, 0);
		blocks[3].position = Position(4, 1);
		break;
	case Pieces::T:
		blocks[1].position = Position(5, 0);//center
		blocks[0].position = Position(4, 0);
		blocks[2].position = Position(6, 0);
		blocks[3].position = Position(5, 1);
		break;
	case Pieces::Z:
		blocks[1].position = Position(5, 0);//center
		blocks[0].position = Position(4, 0);
		blocks[2].position = Position(5, 1);
		blocks[3].position = Position(6, 1);
		break;
	default:
		break;
	}
	blocks[0].type = Type::Filled;
	blocks[1].type = Type::Filled;
	blocks[2].type = Type::Filled;
	blocks[3].type = Type::Filled;
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


bool
Piece::isPossibleMoveDown()
{
	for (int i = 0; i < 4; i++)
	{
		if (board.ActivePiece.blocks[i].position.Y == board.BoardHeight - 1)
		{
			return(false);
		}

		int piece = (board.ActivePiece.blocks[i].position.Y + 1) * board.BoardWidth + board.ActivePiece.blocks[i].position.X;

		if (board.board[piece].type == Type::Filled)
		{
			bool found = false;
			for (int j = 0; j < 4; j++)
			{
				if (i != j &&
					((board.ActivePiece.blocks[i].position.Y + 1) == board.ActivePiece.blocks[j].position.Y &&
					board.ActivePiece.blocks[i].position.X == board.ActivePiece.blocks[j].position.X))
				{
					found = true;
				}
			}
			return found;
		}
	}
}

bool
Piece::isPossibleMoveRight()
{
	for (int i = 0; i < 4; i++)
	{
		if (board.ActivePiece.blocks[i].position.X == board.BoardWidth -1 )
		{
			return(false);
		}
		else
		{
			int pos = board.ActivePiece.blocks[i].position.Y  * board.BoardWidth + board.ActivePiece.blocks[i].position.X + 1;
			if (board.board[pos].type == Type::Filled)
			{
				bool found = false;
				for (int j = 0; j < 4; j++)
				{
					if (i != j &&
						(board.ActivePiece.blocks[i].position.Y == board.ActivePiece.blocks[j].position.Y &&
						(board.ActivePiece.blocks[i].position.X + 1) == board.ActivePiece.blocks[j].position.X))
					{
						found = true;
					}
				}
				return found;
			}
		}
	}
}

bool
Piece::isPossibleMoveLeft()
{
	for (int i = 0; i < 4; i++)
	{
		if (board.ActivePiece.blocks[i].position.X == 0)
		{
			return(false);
		}
		else
		{
			int pos = board.ActivePiece.blocks[i].position.Y  * board.BoardWidth + board.ActivePiece.blocks[i].position.X - 1;
			if (board.board[pos].type == Type::Filled)
			{
				bool found = false;
				for (int j = 0; j < 4; j++)
				{
					if (i != j &&
						(board.ActivePiece.blocks[i].position.Y == board.ActivePiece.blocks[j].position.Y &&
						(board.ActivePiece.blocks[i].position.X - 1) == board.ActivePiece.blocks[j].position.X))
					{
						found = true;
					}
				}
				return found;
			}
		}
	}
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
	if (!board.ActivePiece.isPossibleMoveLeft()){ return; }

	for (int i = 0; i < 4; i++)
	{
		blocks[i].position.X--;
	}
}

void
Piece::MoveRight()
{
	if (!board.ActivePiece.isPossibleMoveRight()){ return; }

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

	for (int i = 0; i < 3; i++)
	{
		newX = blocks[i + 1].position.X - blocks[0].position.X;
		newY = blocks[i + 1].position.Y - blocks[0].position.Y;

		temp = newX;
		newX = -newY;
		newY = temp;

		newX += blocks[0].position.X;
		newY += blocks[0].position.Y;

		blocks[i + 1].position.X = newX;
		blocks[i + 1].position.Y = newY;
	}
}