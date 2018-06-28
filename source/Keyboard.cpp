#include "Keyboard.h"

Keyboard::Keyboard(char keyboard[KEYBOARDSIZE]){
  unsigned i;

  for(i=0;i<KEYBOARDSIZE;i++){
    this->keyboard[i] = keyboard[i];
  }
  caps = true;
  index = 0;
}
void Keyboard::setKeyboard(char keyboard[KEYBOARDSIZE]){
  unsigned i;

  for(i=0;i<KEYBOARDSIZE;i++){
    this->keyboard[i] = keyboard[i];
  }
}
void Keyboard::setCaps(bool caps){
  this->caps = caps;
}
void Keyboard::setIndex(int index){
  this->index = index;
}
bool Keyboard::processKeyboard(bool player_1){
  u32 kDown = Input::getInput();

  if(!kDown) return false; // If no key is pressed return
  if(((kDown & KEY_ZL) && player_1) || ((kDown & KEY_ZR) && !player_1)){
      caps = !caps; // ZL for player 1, ZR for player 2, changes keyboard
  }
  if(((kDown & KEY_L) && player_1) || ((kDown & KEY_R) && !player_1)){
      return true; // If a letter is choosen return
  }
  if(((kDown & KEY_DUP) && player_1) || ((kDown & KEY_X) && !player_1)){
      if(index >= 10){
          index -= 10;
      }
      else{
          index += 30;
      }
  }
  if(((kDown & KEY_DDOWN) && player_1) || ((kDown & KEY_B) && !player_1)){
      if(index <= 29){
          index += 10;
      }
      else{
          index -= 30;
      }
  }
  if(((kDown & KEY_DLEFT) && player_1) || ((kDown & KEY_Y) && !player_1)){
      if(index == 0 || index == 10 || index == 20 || index == 30){
          index += 9;
      }else{
          index--;
      }
  }
  if(((kDown & KEY_DRIGHT) && player_1) || ((kDown & KEY_A) && !player_1)){
      if(index == 9 || index == 19 || index == 29 || index == 39){
          index -= 9;
      }else{
          index++;
      }
  }
  return false;
}
void Keyboard::printKeyboard(bool player_1){
  unsigned i;

  if(player_1) printf("\x1b[4;1H\t\t\t\t\t\t\t\t--Choose your letter Player 1--");
  else printf("\x1b[4;1H\t\t\t\t\t\t\t\t--Choose your letter Player 2--");
  printf("\x1b[7;1H\t\t\t\t\t\t\t\t\t");
  for(i=0;i<KEYBOARDSIZE;i++){
      if(caps){
          if(i == (unsigned)index){
              printf("\x1b[31m%c \x1b[0m",keyboard[i]);
          }else{
              printf("%c ",keyboard[i]);
          }
          if(i == 9 || i == 19 || i == 29) printf("\n\t\t\t\t\t\t\t\t\t");
      }
      else{
          if(i == (unsigned)index){
              printf("\x1b[31m%c \x1b[0m",keyboard[i]);
          }else{
              printf("%c ",keyboard[i]);
          }
          if(i == 9 || i == 19 || i == 29) printf("\n\t\t\t\t\t\t\t\t\t");
      }
  }
}
