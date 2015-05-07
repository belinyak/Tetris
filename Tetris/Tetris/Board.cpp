#include "Board.h"
#include <iostream>

Board::Board( int _BoardWidth, int _BoardHeight)
{
	BoardWidth = _BoardWidth;
	BoardHeight = _BoardHeight;
	board = new Block[BoardWidth*BoardHeight];
}

Board::Board()
{
	BoardWidth = 10;
	BoardHeight = 20;
	board = new Block[BoardWidth*BoardHeight];
}

Board::~Board()
{

}

bool
Board::isPossibleMoveDown()
{
	bool possible = true;
	//ha padló
	for (int i = 0; i < 4; i++)
	{
		if (ActivePiece.blocks[i].position.Y == BoardHeight-1)
		{
			return(false);
		}
	}

	//ha másik elembe ütközik
	for (int i = 0; i < 4; i++)
	{
		int pos = (ActivePiece.blocks[i].position.Y + 1) * BoardWidth + ActivePiece.blocks[i].position.X;

		if (board[pos].type != Type::Empty)
		{
			for (int j = 0; j < 4; j++)
			{
				//TODO(máté):ez itt szar!
				if (i != j &&
					ActivePiece.blocks[j].position.Y * BoardWidth + ActivePiece.blocks[j].position.X == pos)
				{
					possible = false;
				}
			}
		}
	}
	return(possible);
}

void
Board::DeleteRow(int _RowIndex)
{
	for (int i = _RowIndex*BoardWidth;
		i < (_RowIndex + 1)*BoardWidth;
		i++)
	{
		board[i].type = Type::Empty;
	}
}

bool
Board::isGameOver()
{
	for (int i = 0; i < BoardWidth; i++)
	{
		if (board[i].type != Type::Empty)
		{
			for (int j = 0; j < sizeof(ActivePiece.blocks); j++)
			{
				if (ActivePiece.blocks[j].position.X != board[i].position.X ||
					 (ActivePiece.blocks[j].position.Y != board[i].position.Y))
				{
					return(true);
				}
			}
		}
	}
	return(false);
}

void
Board::drawBoard()
{
	std::cout << "\n";

	for (int i = 0; i < BoardWidth ; i++)
	{
		for (int j = 0; j < BoardHeight; j++)
		{
			if (board[i*BoardWidth + j].type == Type::Filled)
			{
				std::cout << "1";
			}
			else
			{
				std::cout << "0";

			}
			//board[i*BoardWidth + j].type == Type::Filled ? std::cout << "1" :  std::cout << "0";

			//std::cout << board[i*BoardWidth + j].type;
		}
		std::cout << "\n";
	}
}

void
Board::AddActivePiecetoBoard()
{
	for (int i = 0; i <4; i++)
	{
		board[(ActivePiece.blocks[i].position.Y) * BoardWidth + ActivePiece.blocks[i].position.X].type =
			Type::Filled;
	}
}

void
Board::RemoveActivePiecefromBoard()
{
	for (int i = 0; i <4; i++)
	{
		board[ActivePiece.blocks[i].position.Y * BoardWidth + ActivePiece.blocks[i].position.X].type =
			Type::Empty;
	}
}
