
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