#include "Player.h"

Player::Player(std::string name, int x, int y){
  unsigned i;
  this->name = name;
  letter = 'A';
  this->x = x;
  this->y = y;
  healt = 3;
  for(i=0;i<INVENTORY;i++){
    inventory[i] = 0;
  }
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
void Player::printStats() const{
  unsigned i;
  printf("\x1b[7;61H|%s's Coords|",name.c_str());
  printf("\x1b[8;61H|-- X: %d Y: %d --|",x,y);
  printf("\x1b[7;1H| %s\'s healt: %d/3 |",name.c_str(),healt);
  printf("\x1b[9;1H| %s\'s inventory |\n",name.c_str());
  for(i=0;i<INVENTORY;i++){
    printf("\n\n");
    switch(inventory[i]){
      case 0:
        printf("-Empty");
        break;
      case 1:
        printf("\x1b[33m-Double movement\x1b[0m");
        break;
      default:
        printf("\x1b[31m-Undefined object\x1b[0m");
        break;
    }
  }
}
