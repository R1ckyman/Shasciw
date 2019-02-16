#include "Keyboard.h"

Keyboard::Keyboard(char keyboard[KEYBOARDSIZE]) {
	unsigned i;

	for (i = 0;i < KEYBOARDSIZE;i++) {
		this->keyboard[i] = keyboard[i];
	}
	caps = true;
	index = 0;
}
void Keyboard::setKeyboard(char keyboard[KEYBOARDSIZE]) {
	unsigned i;

	for (i = 0;i < KEYBOARDSIZE;i++) {
		this->keyboard[i] = keyboard[i];
	}
}
void Keyboard::setCaps(bool caps) {
	this->caps = caps;
}
void Keyboard::setIndex(int index) {
	this->index = index;
}
bool Keyboard::processKeyboard(u64 kDown) {
	if (!kDown) return false; // If no key is pressed return
	if (kDown & ACTION_2) {
		caps = !caps; // ZL for player 1, ZR for player 2, changes keyboard
	}
	if (kDown & ACTION_1) {
		return true; // If a letter is choosen return
	}
	if (kDown & UP) {
		if (index >= 10) {
			index -= 10;
		}
		else {
			index += 30;
		}
	}
	if (kDown & DOWN) {
		if (index <= 29) {
			index += 10;
		}
		else {
			index -= 30;
		}
	}
	if (kDown & LEFT) {
		if (index == 0 || index == 10 || index == 20 || index == 30) {
			index += 9;
		}
		else {
			index--;
		}
	}
	if (kDown & RIGHT) {
		if (index == 9 || index == 19 || index == 29 || index == 39) {
			index -= 9;
		}
		else {
			index++;
		}
	}
	return false;
}
void Keyboard::printKeyboard() {
	unsigned i;
	unsigned y = 0;

	for (i = 0;i < KEYBOARDSIZE;i++) {
		if (i == 0 || i == 10 || i == 20 || i == 30) {
			printf("\x1b[%d;30H", y + 10);
			y += 2;
		}
		if (i == index) {
			printf(ANSI_COLOR_BOLDRED "%c " ANSI_COLOR_RESET, keyboard[i]);
		}
		else {
			printf("%c ", keyboard[i]);
		}
	}
}
void Keyboard::printCurName(char name[8], int name_letters) {
	int i;

	printf("\x1b[4;27H|--Select player name--|");

	// there is a display issue here
	printf("\x1b[6;30H|");
	for (i = 0;i < 8;i++) {
		if (i > name_letters) printf(" %c", '_');
		else printf(" %c", name[i]);
	}
	printf("\x1b[6;48H|");
}
