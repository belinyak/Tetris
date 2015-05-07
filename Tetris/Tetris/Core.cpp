#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <windows.h>                                                                                                                                                                                                                       
#include <GL/gl.h>                                                                                                                                                                                                                
#include <GL/glu.h>                                                                                                                                                                                                               
#include <glut.h>  
#include <time.h>

//#include "Keyboard.h"
#include "Mouse.h"
#include "Configuration.h"
#include "Board.h"
#include "Draw.h"
#include <iostream>


void
onDisplay()
{
	// torlesi szin beallitasa
	glClearColor(0.1f, 0.2f, 0.3f, 1.0f);		
	// kepernyo torles
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	// Buffercsere: rajzolas vege
	glutSwapBuffers();     	
}

Board board = Board(8,12 );


void
onKeyboardDown(unsigned char _key, int _x, int _y)
{
	board.RemoveActivePiecefromBoard();
	switch (_key)
	{
	case 'w':
		board.RemoveActivePiecefromBoard();
		board.ActivePiece.Rotate();
		board.AddActivePiecetoBoard();
		break;
	case 'a':
		board.RemoveActivePiecefromBoard();
		board.ActivePiece.MoveLeft();
		board.AddActivePiecetoBoard();
		break;
	case 'd':
		board.RemoveActivePiecefromBoard();
		board.ActivePiece.MoveRight();
		board.AddActivePiecetoBoard();
		break;
	case 's':
		if (board.isPossibleMoveDown())
		{
			board.RemoveActivePiecefromBoard();
			board.ActivePiece.MoveDown();
			board.AddActivePiecetoBoard();
		}
		else
		{
			int next = 2;// Piece::getNextPiece();
			board.ActivePiece = Piece(next);
			board.AddActivePiecetoBoard();
		}
		break;
	
	default:
		break;
	}
	glutPostRedisplay();

}

static void 
TimerTick(int value)
{
	glutTimerFunc(1000, TimerTick, 0);

	if (board.isPossibleMoveDown())
	{
		board.RemoveActivePiecefromBoard();
		board.ActivePiece.MoveDown();
		board.AddActivePiecetoBoard();
	}
	else
	{
		board.drawBoard();
		int next = 2;// Piece::getNextPiece();
		board.ActivePiece = Piece(next);
		board.AddActivePiecetoBoard();
		board.drawBoard();
	}
	glutPostRedisplay();
}

void 
onInitialization(int argc, char **argv)
{
	glutInit(&argc, argv); 				
	glutInitWindowSize(Configuration::windowWidth, Configuration::windowHeight);
	glutInitWindowPosition(100, 100);		
	// 8 bites R,G,B,A + dupla buffer + melyseg buffer
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);	

	glutCreateWindow( Configuration::gameName);
	

	glViewport(0, 0, Configuration::windowWidth, Configuration::windowHeight);

	//Keyboard Events
	//glutKeyboardUpFunc(onKeyboardUp);
	glutKeyboardFunc(onKeyboardDown);

	//Mouse Events
	glutMotionFunc(Mouse::onMouseMotion);
	glutMouseFunc(Mouse::onMouse);

	glutDisplayFunc(onDisplay);
	// Esemenykezelok regisztralasa
	glutDisplayFunc(Draw::DrawMap);
	//glutDisplayFunc(Draw::DrawGrid);
	glutTimerFunc(2000, TimerTick, 0);


}


int main(int argc, char **argv)
{
	onInitialization(argc, argv);


	srand(time(NULL));


	int next = 2;// Piece::getNextPiece();
	board.ActivePiece = Piece(next);
	board.AddActivePiecetoBoard();
	glutMainLoop();

	std::getchar();

	return(0);
}
