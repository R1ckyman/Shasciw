#include "Bullet.h"

Bullet::Bullet(unsigned x, unsigned y, Dir dir, unsigned player){
  this->x = x;
  this->y = y;
  this->dir = dir;
  this->damage = 1;
  this->player = player;
}
void Bullet::setX(unsigned x){
  this->x = x;
}
void Bullet::setY(unsigned y){
  this->y = y;
}
