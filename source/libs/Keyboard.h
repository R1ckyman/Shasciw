#ifndef _keyboard_H_
#define _keyboard_H_

#include <stdio.h>
#include "Player.h"
#include "Input.h"

const unsigned KEYBOARDSIZE = 40;

class Keyboard {
private:
	char keyboard[KEYBOARDSIZE];
	bool caps;
	unsigned index;
public:
	Keyboard(char keyboard[KEYBOARDSIZE]);
	bool getCaps() const { return caps; };
	int getIndex() const { return index; };
	char getCharacter(int index) const { return keyboard[index]; };
	void setKeyboard(char keyboard[KEYBOARDSIZE]);
	void setCaps(bool caps);
	void setIndex(int index);
	void printKeyboard();
	void printCurName(char name[8], int name_letters);
	bool processKeyboard(u64 kDown);
};

#endif
