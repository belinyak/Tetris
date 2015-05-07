#include <windows.h>                                                                                                                                                                                                              
#include <GL/gl.h>                                                                                                                                                                                                                
#include <GL/glu.h>                                                                                                                                                                                                               
#include <glut.h>                                                                                                                                                                                                              
#include "Board.h"

#include "Draw.h"

extern Board board;

void
Draw::DrawMap()
{
	float cell = 1.8 / (float)board.BoardHeight ;

	for (int i = 0; i < board.BoardHeight*board.BoardWidth; i++)
	{
		int x = i%board.BoardWidth;
		int y = i/board.BoardWidth;


		if (board.board[i].type == Type::Filled)
		{
			glColor3d(1, 1, 0);
		}
		else
		{
			glColor3d(1, 1, 1);
		}

		glRectf(-0.9 + x * cell,
			0.9 - y * cell,
			-0.9 + (x + 1) * cell,
			0.9 - (y+1) * cell);
	}
	DrawGrid();
		glutSwapBuffers();
}


void
Draw::DrawGrid()
{
	float cell = 1.8 / (float)board.BoardHeight;

	for (float i = -0.9; i <= 0.9; i += cell)
	{
		for (float j = 0.9; j >= -0.9; j -= cell)
		{
			glColor3d(0, 0, 0);
			glBegin(GL_LINES);
			glVertex2f(i, j);
			glVertex2f(i, j - cell);
			glVertex2f(i, j);
			glVertex2f(i + cell, j);
			glVertex2f(i + cell, j);
			glVertex2f(i + cell, j - cell);
			glVertex2f(i, j - cell);
			glVertex2f(i + cell, j - cell);
			glEnd();
		}
	}
}

