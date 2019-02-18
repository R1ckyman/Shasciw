#ifndef _Player_H_
#define _Player_H_

#include <stdio.h>
#include <vector>
#include "Bullet.h"

const unsigned INVENTORY = 10;

#define ANSI_COLOR_RED			"\x1b[0;31m"
#define ANSI_COLOR_BOLDRED		"\x1b[1;31m"
#define ANSI_COLOR_GREEN		"\x1b[32m"
#define ANSI_COLOR_BOLDGREEN	"\x1b[1;32m"
#define ANSI_COLOR_YELLOW		"\x1b[33m"
#define ANSI_COLOR_BOLDYELLOW	"\x1b[1;33m"
#define ANSI_COLOR_BLUE			"\x1b[34m"
#define ANSI_COLOR_BOLDBLUE		"\x1b[1;34m"
#define ANSI_COLOR_MAGENTA		"\x1b[0;35m"
#define ANSI_COLOR_BOLDMAGENTA	"\x1b[1;35m"
#define ANSI_COLOR_CYAN			"\x1b[36m"
#define ANSI_COLOR_BOLDCYAN		"\x1b[1;36m"
#define ANSI_COLOR_WHITE		"\x1b[1;37m"
#define ANSI_COLOR_RESET		"\x1b[0m"

class Player {
private:
	unsigned id;
	char name[8];
	char letter;
	int healt;
	unsigned x;
	unsigned y;
	std::vector<unsigned> inventory;
	unsigned moves;
	unsigned maxMoves;
	unsigned damage;
	Dir last_move;
	bool stats_changed;
	bool inventory_changed;
	void removeObject(unsigned object);
public:
	Player(int x, int y, unsigned id);
	char getLetter() const { return letter; };
	int getHealt() const { return healt; };
	unsigned getObject(unsigned index);
	unsigned getX() const { return x; };
	unsigned getY() const { return y; };
	char getName(unsigned position) const { return name[position]; };
	unsigned getMoves() const { return moves; };
	unsigned getMaxMoves() const { return maxMoves; };
	Dir getLastMove() const { return last_move; };
	unsigned getId() const { return id; };
	bool getStatsChanged() const { return stats_changed; };
	bool getInventoryChanged() const { return inventory_changed; };
	unsigned getInventorySize() const { return inventory.size(); };
	unsigned getDamage() const { return damage; };
	void setName(char name[8]);
	void setLetter(char letter);
	void setHealt(int healt);
	void setX(unsigned x);
	void setY(unsigned y);
	void setMoves(unsigned moves);
	void setMaxMoves(unsigned maxMoves);
	void setDamage(unsigned damage);
	void setLastMove(Dir last_move);
	bool addObject(unsigned object);
	void printColor() const;
	void printInfo() const;
	void printStats() const;
	void printInventory(unsigned index = INVENTORY + 1) const;
	void setStatsChanged(bool changed);
	void setInventoryChanged(bool changed);
};

#endif
