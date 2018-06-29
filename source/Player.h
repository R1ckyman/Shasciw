#ifndef _Player_H_
#define _Player_H_

#include <string>
#include <stdio.h>

const unsigned INVENTORY = 10;

class Player{
    private:
        std::string name;
        char letter;
        int healt;
        int x;
        int y;
        int inventory[INVENTORY];
    public:
        Player(std::string name, int x, int y);
        char getLetter() const { return letter; };
        int getHealt() const { return healt; };
        int getObject(unsigned i) const{ return inventory[i]; };
        int getX() const { return x; };
        int getY() const { return y; };
        void setX(unsigned x);
        void setY(unsigned y);
        void setLetter(char letter);
        void setHealt(int healt);
        void printStats() const;
};

#endif
