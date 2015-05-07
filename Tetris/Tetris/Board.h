#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include "Block.h"
#include "Piece.h"


class Board
{
public:
	Piece ActivePiece;
	int BoardWidth;
	int BoardHeight;
	Block* board;


	Board();
	Board(int _BoardWidth,int _BoardHeight);
	~Board();

	void drawBoard();
	void AddActivePiecetoBoard();
	void RemoveActivePiecefromBoard();

	bool isPossibleMoveDown();
private:
	void DeleteRow(int _RowIndex);

	bool isGameOver();

	//Board(const Board& other);
	Board& operator=(const Board& other);
};


#endif