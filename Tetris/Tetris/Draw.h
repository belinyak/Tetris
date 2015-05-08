#ifndef DRAW_H
#define DRAW_H                 

#include "Board.h"

static class Draw
{
public:
	static void DrawMap(Board* _board);
	static void DrawMap();
	static void DrawGrid();
};

#endif