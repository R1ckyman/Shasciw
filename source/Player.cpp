#include "Player.h"
#include <cstring>

Player::Player(char name[9], int x, int y){
  unsigned i;
  strcpy(this->name, name);
  letter = 'A';
  this->x = x;
  this->y = y;
  healt = 3;
  for(i=0;i<INVENTORY;i++){
    inventory[i] = 0;
  }
}
void Player::setName(char name[9]){
  strcpy(this->name, name);
}
void Player::setLetter(char letter){
  this->letter = letter;
}
void Player::setHealt(int healt){
  this->healt = healt;
}
void Player::setX(unsigned x){
  this->x = x;
}
void Player::setY(unsigned y){
  this->y = y;
}
void Player::printStats(unsigned index) const{
  unsigned i;
  printf("\x1b[7;60H|%s's Coords\x1b[7;77H|",name);
  printf("\x1b[8;60H|- X: %d Y: %d -\x1b[8;77H|",x,y);
  printf("\x1b[7;1H| %s\'s healt: %d/3 \x1b[7;24H|",name,healt);
  printf("\x1b[9;1H| %s\'s inventory \x1b[9;24H|",name);
  for(i=0;i<INVENTORY;i++){
    printf("\n\n\t");
    if(i == index) printf("\x1b[33m");
    switch(inventory[i]){
      case 0:
        printf("-Empty           ");
        break;
      case 1:
        printf("-Double movement ");
        break;
      default:
        printf("-Undefined object");
        break;
    }
    printf("\x1b[0m");
  }
}
