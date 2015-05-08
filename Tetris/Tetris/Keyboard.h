#ifndef GAME_KEYBOARD_H
#define GAME_KEYBOARD_H

enum Actions
{
	Up,
	Right,
	Left
};

class Keyboard
{
public:
	Actions action;
	void onKeyboardDown(unsigned char _key, int _x, int _y);
	void onKeyboardUp(unsigned char _key, int _x, int _y);
};
#endif