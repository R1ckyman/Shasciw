#ifndef _Bullet_H_
#define _Bullet_H_

enum Dir{
  DIR_UP,
  DIR_DOWN,
  DIR_RIGHT,
  DIR_LEFT
};

class Bullet{
    private:
        Dir dir;
        unsigned x;
        unsigned y;
        unsigned damage;
    public:
        Bullet(unsigned x, unsigned y, Dir dir);
        unsigned getX() const { return x; };
        unsigned getY() const { return y; };
        unsigned getDir() const { return dir; };
        unsigned getDamage() const { return damage; };
        void setX(unsigned x);
        void setY(unsigned y);
};

#endif
