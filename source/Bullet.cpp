#include "Bullet.h"

Bullet::Bullet(unsigned x, unsigned y, Dir dir){
  this->x = x;
  this->y = y;
  this->dir = dir;
  this->damage = 1;
}
void Bullet::setX(unsigned x){
  this->x = x;
}
void Bullet::setY(unsigned y){
  this->y = y;
}
