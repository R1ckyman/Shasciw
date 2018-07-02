#include "Door.h"

Door::Door(unsigned x, unsigned y){
  this->x = x;
  this->y = y;

  closed = true;
  time = 3;
}
void Door::setClosed(bool closed){
  this->closed = closed;
}
void Door::setTime(){
  if(time > 0) time--;
}
