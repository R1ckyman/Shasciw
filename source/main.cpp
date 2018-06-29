#include "Keyboard.h"
#include "Map.h"

int main(int argc, char **argv)
{
	/*char keysNames[32][32] = {
        "KEY_A", "KEY_B", "KEY_X", "KEY_Y",
        "KEY_LSTICK", "KEY_RSTICK", "KEY_L", "KEY_R",
        "KEY_ZL", "KEY_ZR", "KEY_PLUS", "KEY_MINUS",
        "KEY_DLEFT", "KEY_DUP", "KEY_DRIGHT", "KEY_DDOWN",
        "KEY_LSTICK_LEFT", "KEY_LSTICK_UP", "KEY_LSTICK_RIGHT", "KEY_LSTICK_DOWN",
        "KEY_RSTICK_LEFT", "KEY_RSTICK_UP", "KEY_RSTICK_RIGHT", "KEY_RSTICK_DOWN",
        "KEY_SL", "KEY_SR", "KEY_TOUCH", "",
        "", "", "", ""
    };
    */
  char keyboard_1[KEYBOARDSIZE] = {'0','1','2','3','4','5','6','7','8','9',
                              'A','B','C','D','F','G','H','I','J','K',
                              'L','M','N','O','P','Q','R','S','T','U',
                              'V','W','X','Y','Z','$','/','@','%','&'};
  char keyboard_2[KEYBOARDSIZE] = {'0','1','2','3','4','5','6','7','8','9',
                              'a','b','c','d','f','g','h','i','j','k',
                              'l','m','n','o','p','q','r','s','t','u',
                              'v','w','x','y','z','<','=','*','?','!'};

  bool r_pressed = false;
  bool l_pressed = false;
  bool name = false;
  bool game = false;
  bool player_1 = true;

  Map map;
  Keyboard keyboard(keyboard_1);
  Player temp_player = map.getPlayer(0);

  gfxInitDefault();
  consoleInit(NULL);

  printf("\x1b[2;24H\x1b[32mPress L and R to start the game.\x1b[0m");
  printf("\x1b[4;24H\x1b[33mPress + to return Homebrew menu.\x1b[0m");
  printf("\x1b[11;1H[Input] - Player 1");
  printf("\x1b[13;1H-%c, %c, %c, %c, to control the character and keyboard [ZL to switch caps]",24,25,26,27);
  printf("\x1b[15;1H-L to shoot and %c, %c, %c, %c, to select the direction",24,25,26,27);
  printf("\x1b[17;1H-ZR to open inventory and L to use an object");
  printf("\x1b[19;1H[Input] - Player 2");
  printf("\x1b[21;1H-X,B,A,Y to control the character and keyboard [ZR to switch caps]");
  printf("\x1b[23;1H-R to shoot and X,B,A,Y to select the direction");
  printf("\x1b[25;1H-ZR to open inventory and R to use an object");

  // Main loop
  while(appletMainLoop())
  {
    //Scan all the inputs. This should be done once for each frame
    hidScanInput();

    u32 kDown = Input::getInput();

    if (kDown & KEY_PLUS) break; // return Hb menu
    if(name){
      if(keyboard.getCaps()) keyboard.setKeyboard(keyboard_1);
      else keyboard.setKeyboard(keyboard_2);
        if(player_1){
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
          if(keyboard.processKeyboard(player_1)){
            if(keyboard.getCharacter(keyboard.getIndex()) != map.getPlayer(0).getLetter()){
              temp_player = map.getPlayer(1);
              temp_player.setLetter(keyboard.getCharacter(keyboard.getIndex()));
              map.modifyPlayer(1,temp_player);
              keyboard.setCaps(true);
              keyboard.setIndex(0);
              player_1 = true;
              game = true;
              name = false;
              consoleClear();
              map.printMap(player_1);
            }
            else printf("\x1b[7;55H\\|Letter already chosen|/");
          }
          else keyboard.printKeyboard(player_1);
        }
    }
    else if(!game){
      if(kDown & KEY_L){
        l_pressed = true;
      }
      if(kDown & KEY_R){
        r_pressed = true;
      }
      if(l_pressed && r_pressed){
        consoleClear();
        name = true;
      }
    }
    else if(game){
        if(player_1) temp_player = map.getPlayer(0);
        else temp_player = map.getPlayer(1);
        if(map.gameProcess(temp_player, player_1)){
          if(player_1) map.modifyPlayer(0,temp_player);
          else map.modifyPlayer(1,temp_player);
          player_1 = !player_1;
          map.printMap(player_1);
        }
    }
    gfxFlushBuffers();
    gfxSwapBuffers();
    gfxWaitForVsync();
  }

  gfxExit();
  return 0;
}
