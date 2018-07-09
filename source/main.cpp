#include "Keyboard.h"
#include "Map.h"

void printMenu(const bool first_time, const bool player_1_won, const Map map){
  if(!first_time){
    unsigned i;
    printf("\x1b[1;2H\x1b[31m--- ");
    for(i=0;i<8;i++){
      if(player_1_won) printf("%c",map.getPlayer(0).getName(i));
      else printf("%c",map.getPlayer(1).getName(i));
    }
    printf(" won---\x1b[0m");
    printf("\x1b[2;2H\x1b[32m---L & R to retry--\x1b[0m");
  }
  printf("\x1b[2;24H\x1b[32mPress L and R to start the game\x1b[0m");
  printf("\x1b[4;24H\x1b[32mPress -, before L and R to quickplay\x1b[0m");
  printf("\x1b[7;24H\x1b[33mPress + to return Homebrew menu\x1b[0m");
  printf("\x1b[11;1H\x1b[33m[Input] - Player 1\x1b[0m");
  printf("\x1b[13;1H[Keyboard] - Player 1");
  printf("\x1b[15;3H-%c, %c, %c, %c, to control the keyboard",24,25,26,27);
  printf("\x1b[15;3H-Press L stick to enter the name, ZL to switch caps");
  printf("\x1b[17;3H-Move left(Left stick) to delete, move right(Right stick) to space");
  printf("\x1b[19;1H[Game] - Player 1");
  printf("\x1b[21;3H-%c, %c, %c, %c, to control the character",24,25,26,27);
  printf("\x1b[23;3H-L to select action: shoot/open and %c, %c, %c, %c, to select the direction",24,25,26,27);
  printf("\x1b[25;3H-ZR to open inventory and L to use an object");
  printf("\x1b[27;1H\x1b[33m[Input] - Player 2\x1b[0m");
  printf("\x1b[29;1H[Keyboard] - Player 2");
  printf("\x1b[31;3H-X,B,A,Y to control the keyboard");
  printf("\x1b[33;3H-Press R stick to enter the name, ZR to switch caps");
  printf("\x1b[35;3HMove left(Right stick) to delete, move right(Right stick) to space");
  printf("\x1b[37;1H[Game] - Player 2");
  printf("\x1b[39;3H-X,B,A,Y to control the character");
  printf("\x1b[41;3H-R to select action: shoot/open and X,B,A,Y to select the direction");
  printf("\x1b[43;3H-ZR to open inventory and R to use an object");
}
int main(int argc, char **argv)
{
  char keyboard_1[KEYBOARDSIZE] = {'0','1','2','3','4','5','6','7','8','9',
                              'A','B','C','D','F','G','H','I','J','K',
                              'L','M','N','O','P','Q','R','S','T','U',
                              'V','W','X','Y','Z','$','/','@','%','&'};
  char keyboard_2[KEYBOARDSIZE] = {'0','1','2','3','4','5','6','7','8','9',
                              'a','b','c','d','f','g','h','i','j','k',
                              'l','m','n','o','p','q','r','s','t','u',
                              'v','w','x','y','z','<','=','*','?','!'};
  char temp_name[8] = {'\0','\0','\0','\0','\0','\0','\0','\0'};

  bool r_pressed = false;
  bool l_pressed = false;
  bool minus_pressed = false;
  bool letter = false;
  bool name = false;
  bool game = false;
  bool player_1 = true;
  bool player_1_won = false;
  bool finished = false;

  int name_letters = 0;
  int special = 0;
  int inventory_index = -1;
  int moves = 2;
  int i;

  Map map;
  Keyboard keyboard(keyboard_1);
  Player temp_player = map.getPlayer(0);

  gfxInitDefault();
  consoleInit(NULL);

  printMenu(true, player_1_won, map);

  // Main loop
  while(appletMainLoop())
  {
    //Scan all the inputs. This should be done once for each frame
    hidScanInput();

    u32 kDown = Input::getInputDown();

    if (kDown & KEY_PLUS) break; // return Hb menu

    if(game){
      if(map.getPlayer(0).getHealt() > 0 || map.getPlayer(1).getHealt() > 0){
        if(player_1) temp_player = map.getPlayer(0);
        else temp_player = map.getPlayer(1);
        if(map.processGame(temp_player, player_1, special, inventory_index, kDown)){
          if(player_1) map.modifyPlayer(0,temp_player);
          else map.modifyPlayer(1,temp_player);
          if(moves <= 0){
            player_1 = !player_1;
            moves = 2;
          }
          else moves--;
          map.printMap(player_1);
        }
      }
      else{
        game = false;
        finished = true;
        if(map.getPlayer(0).getHealt() <= 0) player_1_won = false;
        else player_1_won = true;
      }
    }
    else if(name){
      if(keyboard.getCaps()) keyboard.setKeyboard(keyboard_1);
      else keyboard.setKeyboard(keyboard_2);
      if(player_1){
        keyboard.printCurName(player_1, temp_name, name_letters);
        if (kDown & KEY_LSTICK_LEFT){
          name_letters--;
          temp_name[name_letters] = '\0';
        }
        if (kDown & KEY_LSTICK_RIGHT){
          if(name_letters < 7){
            temp_name[name_letters] = ' ';
            name_letters++;
          }
        }
        if (kDown & KEY_LSTICK){
          temp_player = map.getPlayer(0);
          temp_player.setName(temp_name);
          map.modifyPlayer(0, temp_player);
          keyboard.setCaps(true);
          keyboard.setIndex(0);
          player_1 = false;
          name_letters = 0;
          for(i=0;i<8;i++) temp_name[i] = '\0';
        }
        if(keyboard.processKeyboard(player_1)){
          if(name_letters < 7){
            temp_name[name_letters] = keyboard.getCharacter(keyboard.getIndex());
            name_letters++;
          }
          else printf("\x1b[8;46H--Max name length reached--");
        }
        else keyboard.printKeyboard(player_1);
      }
      else{
        keyboard.printCurName(player_1, temp_name, name_letters);
        if (kDown & KEY_RSTICK_LEFT){
          name_letters--;
          temp_name[name_letters] = '\0';
        }
        if (kDown & KEY_LSTICK_RIGHT){
          if(name_letters < 7){
            temp_name[name_letters] = ' ';
            name_letters++;
          }
        }
        if (kDown & KEY_RSTICK){
          temp_player = map.getPlayer(1);
          temp_player.setName(temp_name);
          map.modifyPlayer(1, temp_player);
          keyboard.setCaps(true);
          keyboard.setIndex(0);
          player_1 = true;
          name = false;
          letter = true;
          consoleClear();
        }
        if(keyboard.processKeyboard(player_1)){
          if(name_letters < 7){
            temp_name[name_letters] = keyboard.getCharacter(keyboard.getIndex());
            name_letters++;
          }
          else printf("\x1b[8;46H--Max name length reached--");
        }
        else keyboard.printKeyboard(player_1);
      }
    }
    else if(letter){
      if(keyboard.getCaps()) keyboard.setKeyboard(keyboard_1);
      else keyboard.setKeyboard(keyboard_2);
      if(player_1){
        printf("\x1b[4;24H--Choose your letter Player 1--");
        if(keyboard.processKeyboard(player_1)){
            temp_player = map.getPlayer(0);
            temp_player.setLetter(keyboard.getCharacter(keyboard.getIndex()));
            map.modifyPlayer(0,temp_player);
            keyboard.setCaps(true);
            keyboard.setIndex(0);
            player_1 = false;
          }
        else keyboard.printKeyboard(player_1);
      }
      else{
        printf("\x1b[4;24H--Choose your letter Player 2--");
        if(keyboard.processKeyboard(player_1)){
          if(keyboard.getCharacter(keyboard.getIndex()) != map.getPlayer(0).getLetter()){
            temp_player = map.getPlayer(1);
            temp_player.setLetter(keyboard.getCharacter(keyboard.getIndex()));
            map.modifyPlayer(1,temp_player);
            keyboard.setCaps(true);
            keyboard.setIndex(0);
            player_1 = true;
            game = true;
            letter = false;
            consoleClear();
            map.printMap(player_1);
          }
          else printf("\x1b[7;55H\\|Letter already chosen|/");
        }
        else keyboard.printKeyboard(player_1);
      }
    }
    else if(!game){
      if(!finished){
        if(kDown & KEY_L){
          l_pressed = true;
        }
        if(kDown & KEY_R){
          r_pressed = true;
        }
        if(kDown & KEY_MINUS){
          minus_pressed = true;
        }
        if(l_pressed && r_pressed){
          consoleClear();
          if(minus_pressed) letter = true;
          else name = true;
        }
      }
      else{
        consoleClear();
        printMenu(false, player_1_won, map);
        finished = false;
      }
    }

    gfxFlushBuffers();
    gfxSwapBuffers();
    gfxWaitForVsync();
  }

  gfxExit();
  return 0;
}
