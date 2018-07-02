#ifndef _Player_H_
#define _Player_H_

#include <stdio.h>

const unsigned INVENTORY = 10;

class Player{
    private:
        char name[8];
        char letter;
        int healt;
        unsigned x;
        unsigned y;
        int inventory[INVENTORY];
    public:
        Player(char name[8], int x, int y);
        char getLetter() const { return letter; };
        int getHealt() const { return healt; };
        int getObject(unsigned i) const { return inventory[i]; };
        unsigned getX() const { return x; };
        unsigned getY() const { return y; };
        void setName(char name[8]);
        void setLetter(char letter);
        void setHealt(int healt);
        void setX(unsigned x);
        void setY(unsigned y);
        void printStats(unsigned index) const;
};

#endif
