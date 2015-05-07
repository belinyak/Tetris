#include "Keyboard.h"
#include <glut.h>

void
Keyboard::onKeyboardDown(unsigned char _key, int _x, int _y)
{
	switch (_key)
	{
	case 'w':
		action = Actions::Up;
		glutPostRedisplay();
		break;
	case 'a':
		action = Actions::Left;
		break;
	case 'd':
		action = Actions::Right;
		break;
	default:
		break;
	}
}

void
Keyboard::onKeyboardUp(unsigned char _key, int _x, int _y)
{
}