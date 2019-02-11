#include "Door.h"

Door::Door(unsigned x, unsigned y) {
	this->x = x;
	this->y = y;

	open = false;
	time = 5;
}
void Door::setOpen(bool open) {
	if (open == false) time = 5;
	this->open = open;
}
void Door::setTime() {
	if (time > 0) time--;
}
