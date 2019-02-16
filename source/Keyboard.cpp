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
		if (index >= 10 && index <= 39) {
			index -= 10;
		}
		else if (index == 40) {
			index = 31;
		}
		else if (index == 41) {
			index = 38;
		}
		else if (index <= 4) {
			index = 40;
		}
		else {
			index = 41;
		}
	}
	if (kDown & DOWN) {
		if (index <= 29) {
			index += 10;
		}
		else if (index <= 34) {
			index = 40;
		}
		else if (index == 40) {
			index = 1;
		}
		else if (index == 41) {
			index = 8;
		}
		else index = 41;
	}
	if (kDown & LEFT) {
		if (index == 0 || index == 10 || index == 20 || index == 30) {
			index += 9;
		}
		else if (index == 40) {
			index = 41;
		}
		else {
			index--;
		}
	}
	if (kDown & RIGHT) {
		if (index == 9 || index == 19 || index == 29) {
			index -= 9;
		}
		else if (index == 41) {
			index = 40;
		}
		else {
			index++;
		}
	}
	return false;
}
void Keyboard::printKeyboard() {
	unsigned i;
	unsigned y = 4;

	for (i = 0;i < KEYBOARDSIZE;i++) {
		if (i == 0 || i == 10 || i == 20 || i == 30 || i == 40) {
			printf("\x1b[%d;29H", y + 10);
			y += 2;
		}
		if (i == index) {
			if (keyboard[i] == '\\') printf(ANSI_COLOR_BOLDGREEN "Confirm" ANSI_COLOR_RESET);
			else if (keyboard[i] == '\n') printf(ANSI_COLOR_BOLDRED "Delete       " ANSI_COLOR_RESET);
			else if (keyboard[i] == ' ') printf(ANSI_COLOR_BOLDYELLOW "_" ANSI_COLOR_RESET);
			else printf(ANSI_COLOR_BOLDCYAN "%c " ANSI_COLOR_RESET, keyboard[i]);
		}
		else {
			if (keyboard[i] == '\\') printf(ANSI_COLOR_GREEN "Confirm" ANSI_COLOR_RESET);
			else if (keyboard[i] == '\n') printf(ANSI_COLOR_RED "Delete       " ANSI_COLOR_RESET);
			else if (keyboard[i] == ' ') printf(ANSI_COLOR_YELLOW "_" ANSI_COLOR_RESET);
			else printf(ANSI_COLOR_CYAN "%c " ANSI_COLOR_RESET, keyboard[i]);
		}
	}
}
void Keyboard::printCurName(char name[8], int name_letters) {
	int i;

	printf("\x1b[6;26H|--Select player name--|");

	// there is a display issue here
	printf("\x1b[8;29H|");
	for (i = 0;i < 8;i++) {
		if (i > name_letters) printf(" %c", '_');
		else printf(" %c", name[i]);
	}
	printf("\x1b[8;48H|");
}
