#ifndef _Player_H_
#define _Player_H_

#include <stdio.h>
#include "Bullet.h"

const unsigned INVENTORY = 10;

class Player{
  private:
    unsigned id;
    char name[8];
    char letter;
    int healt;
    unsigned x;
    unsigned y;
    int inventory[INVENTORY];
    unsigned moves;
    unsigned maxMoves;
    Dir last_move;
    bool stats_changed;
  public:
    Player(char name[8], int x, int y, unsigned id);
    char getLetter() const { return letter; };
    int getHealt() const { return healt; };
    int getObject(unsigned i) const { return inventory[i]; };
    unsigned getX() const { return x; };
    unsigned getY() const { return y; };
    char getName(unsigned position) const { return name[position]; };
    unsigned getMoves() const { return moves; };
    unsigned getMaxMoves() const { return maxMoves; };
    Dir getLastMove() const { return last_move; };
    unsigned getId() const { return id; };
    bool getStatsChanged() const {return stats_changed; };
    void setName(char name[8]);
    void setLetter(char letter);
    void setHealt(int healt);
    void setX(unsigned x);
    void setY(unsigned y);
    void setMoves(unsigned moves);
    void setMaxMoves(unsigned maxMoves);
    void setLastMove(Dir last_move);
    void printInfo() const;
    void printStats(unsigned index) const;
    void setStatsChanged(bool changed);
};

#endif
