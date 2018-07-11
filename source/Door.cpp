#include "Door.h"

Door::Door(unsigned x, unsigned y){
  this->x = x;
  this->y = y;

  open = false;
  time = 4;
}
void Door::setOpen(bool open){
  this->open = open;
}
void Door::setTime(){
  if(time > 0) time--;
}
