#ifndef _Bullet_H_
#define _Bullet_H_

enum Dir{
  DIR_UP,
  DIR_DOWN,
  DIR_RIGHT,
  DIR_LEFT,
  DIR_NULL
};

class Bullet{
  private:
    Dir dir;
    unsigned x;
    unsigned y;
    unsigned damage;
    unsigned player;
  public:
    Bullet(unsigned x, unsigned y, Dir dir, unsigned player);
    unsigned getX() const { return x; };
    unsigned getY() const { return y; };
    unsigned getDir() const { return dir; };
    unsigned getDamage() const { return damage; };
    unsigned getPlayer() const { return player; };
    void setX(unsigned x);
    void setY(unsigned y);
};

#endif
