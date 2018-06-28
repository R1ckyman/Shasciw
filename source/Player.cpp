#include "Player.h"

Player::Player(std::string name,int x, int y){
  unsigned i;
  this->name = name;
  letter = 'O';
  healt = 3;
  this->x = x;
  this->y = y;
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
void Player::printStats() const{
  unsigned i;
  printf("\x1b[8;1H\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|Posicion actual|");
  printf("\x1b[9;1H\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tX: %d Y: %d",x,y);
  printf("\x1b[10;1H\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tHealth: %d",healt);
  printf("\x1b[7;1H--%s\' inventory",name.c_str());
  for(i=0;i<INVENTORY;i++){
    printf("\n");
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
  }
}
