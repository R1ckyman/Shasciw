#include "Player.h"
#include <cstring>

Player::Player(char name[9], int x, int y, unsigned id) {
	strcpy(this->name, name);
	letter = 'A';
	this->x = x;
	this->y = y;
	healt = 3;
	moves = 3;
	maxMoves = 3;
	damage = 1;
	last_move = DIR_NULL;
	this->id = id;
	stats_changed = false;
	inventory_changed = false;
	inventory.push_back(0);
}
void Player::setName(char name[9]) {
	strcpy(this->name, name);
}
void Player::setLetter(char letter) {
	this->letter = letter;
}
void Player::setHealt(int healt) {
	this->healt = healt;
}
void Player::setX(unsigned x) {
	this->x = x;
}
void Player::setY(unsigned y) {
	this->y = y;
}
void Player::setMoves(unsigned moves) {
	this->moves = moves;
}
void Player::setMaxMoves(unsigned maxMoves) {
	this->maxMoves = maxMoves;
}
void Player::setDamage(unsigned damage) {
	this->damage = damage;
}
void Player::setLastMove(Dir dir) {
	last_move = dir;
}
void Player::setStatsChanged(bool changed) {
	stats_changed = changed;
}
void Player::setInventoryChanged(bool changed) {
	inventory_changed = changed;
}
bool Player::addObject(unsigned object) {
	if (inventory.size() < INVENTORY) {
		inventory.push_back(object);
		return true;
	}
	return false;
}
void Player::printInfo() const {
	printf("\x1b[9;60H->Moves: %u", moves + 1);
}
void Player::printStats() const {
	printf("\x1b[7;1H| %s\'s healt: %d/3 \x1b[7;24H|", name, healt);
	printf("\x1b[9;1H| %s\'s inventory \x1b[9;24H|", name);
}
void Player::removeObject(unsigned object) {
	for (unsigned i = 0;i < inventory.size();i++)
		if (object == inventory[i])
			inventory.erase(inventory.begin() + i);
}

unsigned Player::getObject(unsigned index) {
	unsigned object = inventory[index];
	removeObject(object);

	return object;
}
void Player::printInventory(unsigned index) const {
	unsigned i;
	for (i = 0;i < INVENTORY;i++) {
		printf("\x1b[%d;1H", 11 + i * 2);
		if (i < getInventorySize()) {
			if (i == index) printf("\x1b[31m");
			switch (inventory[i]) {
			case 0:
				printf("-Add 1 move      ");
				break;
			case 1:
				printf("-Add 2 moves     ");
				break;
			case 2:
				printf("-Add 3 moves     ");
				break;
			case 3:
				printf("-[P] Add 1 move  ");
				break;
			case 4:
				printf("-Add 1 damage    ");
				break;
			default:
				printf("-Undefined object");
				break;
			}
			if (i == index) printf("\x1b[0m");
		}
		else printf("                 ");
	}
}
