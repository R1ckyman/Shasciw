#include "Keyboard.h"
#include "Map.h"

void printControls() {
	consoleClear();
	printf(ANSI_COLOR_BOLDYELLOW "\x1b[2;24HReturn to main menu (+)" ANSI_COLOR_RESET);
	printf("\x1b[6;1H\x1b[33m[Input] - Player 1\x1b[0m");
	printf("\x1b[8;1H[Keyboard] - Player 1");
	printf("\x1b[10;3H-%c, %c, %c, %c, to control the keyboard", 24, 25, 26, 27);
	printf("\x1b[12;3H-Move up(Left stick) to enter the name, ZL to switch caps");
	printf("\x1b[14;3H-Move left(Left stick) to delete, move right(Right stick) to space");
	printf("\x1b[16;1H[Game] - Player 1");
	printf("\x1b[18;3H-%c, %c, %c, %c, to control the character", 24, 25, 26, 27);
	printf("\x1b[20;3H-L to select action: shoot/open and %c, %c, %c, %c, to select the direction", 24, 25, 26, 27);
	printf("\x1b[22;3H-ZR to open inventory and L to use an object");
	printf("\x1b[24;1H\x1b[33m[Input] - Player 2\x1b[0m");
	printf("\x1b[26;1H[Keyboard] - Player 2");
	printf("\x1b[28;3H-X,B,A,Y to control the keyboard");
	printf("\x1b[30;3H-Move up(Right stick) to enter the name, ZR to switch caps");
	printf("\x1b[32;3HMove left(Right stick) to delete, move right(Right stick) to space");
	printf("\x1b[34;1H[Game] - Player 2");
	printf("\x1b[36;3H-X,B,A,Y to control the character");
	printf("\x1b[38;3H-R to select action: shoot/open and X,B,A,Y to select the direction");
	printf("\x1b[40;3H-ZR to open inventory and R to use an object");
}
void printMenu(unsigned index = 0) {
	if (index == 0) printf(ANSI_COLOR_BOLDRED);
	else printf(ANSI_COLOR_RED);
	printf("\x1b[4;27HQuickplay (-)" ANSI_COLOR_RESET);
	if (index == 1) printf(ANSI_COLOR_BOLDYELLOW);
	else printf(ANSI_COLOR_YELLOW);
	printf("\x1b[8;27HName selector" ANSI_COLOR_RESET);
	if (index == 2) printf(ANSI_COLOR_BOLDGREEN);
	else printf(ANSI_COLOR_GREEN);
	printf("\x1b[12;27HLoad saved game (not yet)" ANSI_COLOR_RESET);
	if (index == 3) printf(ANSI_COLOR_BOLDCYAN);
	else printf(ANSI_COLOR_CYAN);
	printf("\x1b[16;27HControls menu" ANSI_COLOR_RESET);
	if (index == 4) printf(ANSI_COLOR_BOLDMAGENTA);
	else printf(ANSI_COLOR_MAGENTA);
	printf("\x1b[20;27HReturn to Homebrew menu (+)" ANSI_COLOR_RESET);
}
void printWinner(unsigned player, const Map &map) {
	unsigned i;

	switch (player)
	{
	case 0:
		printf(ANSI_COLOR_BOLDYELLOW);
		break;
	default:
		printf(ANSI_COLOR_BOLDGREEN);
		break;
	}
	printf("\x1b[23;24H--- ");
	for (i = 0;i < 8;i++) {
		printf("%c", map.getPlayer(player).getName(i));
	}
	printf(" won---" ANSI_COLOR_RESET);

	printMenu();
}
void restart(Map &map) {
	Map temp_map;
	map = temp_map;
	consoleClear();
}
int main(int argc, char **argv)
{
	char keyboard_1[KEYBOARDSIZE] = { '0','1','2','3','4','5','6','7','8','9',
								'A','B','C','D','F','G','H','I','J','K',
								'L','M','N','O','P','Q','R','S','T','U',
								'V','W','X','Y','Z','$','/','@','%','&' };
	char keyboard_2[KEYBOARDSIZE] = { '0','1','2','3','4','5','6','7','8','9',
								'a','b','c','d','f','g','h','i','j','k',
								'l','m','n','o','p','q','r','s','t','u',
								'v','w','x','y','z','<','=','>','?','!' };
	char temp_name[8] = { '\0','\0','\0','\0','\0','\0','\0','\0' };

	bool active = true;
	bool next_player = false;

	int i;
	int name_letters = 0;
	int special = 0;

	unsigned state = 0;
	unsigned inventory_index = 0;
	unsigned menu_index = 0;
	unsigned player_index = 0;
	
	Map map;
	Keyboard keyboard(keyboard_1);
	Player temp_player = map.getPlayer(0);

	gfxInitDefault();
	consoleInit(NULL);

	printMenu();

	// Main loop
	while (active)
	{
		//Scan all the inputs. This should be done once for each frame
		hidScanInput();

		u64 kDown = Input::getInputDown();

		switch (state) {
		case 0: // Main menu
			if ((kDown & KEY_DDOWN) || (kDown & KEY_B)) {
				if (menu_index < 4) menu_index++;
				printMenu(menu_index);
			}
			if ((kDown & KEY_DUP) || (kDown & KEY_X)) {
				if (menu_index > 0) menu_index--;
				printMenu(menu_index);
			}
			if ((kDown & KEY_L) || (kDown & KEY_R)) {
				switch (menu_index)
				{
				case 0: // Quickplay
					consoleClear();
					map.printMapFull(map.getPlayer(player_index));
					state = 4;
					break;
				case 1: // Name selector
					consoleClear();
					state = 2;
					break;
				case 2: // Print Controls
					state = 1;
					printControls();
					break;
				case 3:
					break;
				default: // Return HB menu
					active = false;
					break;
				}
				menu_index = 0;
			}
			if (kDown & KEY_MINUS) {
				consoleClear();
				map.printMapFull(map.getPlayer(player_index));
				state = 4;
			}
			break;
		case 1: // Controls menu
			if ((kDown & KEY_L) || (kDown & KEY_R)) {
				consoleClear();
				printMenu();
				state = 0;
			}
			break;
		case 2: // Choosing name process
			if (keyboard.getCaps()) keyboard.setKeyboard(keyboard_1);
			else keyboard.setKeyboard(keyboard_2);

			switch (player_index)
			{
			case 0:
				keyboard.printCurName(temp_name, name_letters);
				if (kDown & KEY_LSTICK_LEFT) {
					if (name_letters > 0) {
						printf("\x1b[8;27H%27c", ' ');
						name_letters--;
						temp_name[name_letters] = '\0';
					}
				}
				if (kDown & KEY_LSTICK_RIGHT) {
					if (name_letters < 7) {
						temp_name[name_letters] = ' ';
						name_letters++;
					}
				}
				if (kDown & KEY_LSTICK_UP) {
					temp_player = map.getPlayer(player_index);
					temp_player.setName(temp_name);
					map.modifyPlayer(player_index, temp_player);
					keyboard.setCaps(true);
					keyboard.setIndex(0);
					player_index = 1;
					name_letters = 0;
					consoleClear();
					for (i = 0;i < 8;i++) temp_name[i] = '\0';
				}
				if (keyboard.processKeyboard(player_index)) {
					if (name_letters < 7) {
						temp_name[name_letters] = keyboard.getCharacter(keyboard.getIndex());
						name_letters++;
					}
					else printf("\x1b[8;27H--Max name length reached--");
				}
				else keyboard.printKeyboard();
				break;
			default:
				keyboard.printCurName(temp_name, name_letters);
				if (kDown & KEY_RSTICK_LEFT) {
					if (name_letters > 0) {
						printf("\x1b[8;27H%27c", ' ');
						name_letters--;
						temp_name[name_letters] = '\0';
					}
				}
				if (kDown & KEY_LSTICK_RIGHT) {
					if (name_letters < 7) {
						temp_name[name_letters] = ' ';
						name_letters++;
					}
				}
				if (kDown & KEY_RSTICK_UP) {
					temp_player = map.getPlayer(player_index);
					temp_player.setName(temp_name);
					map.modifyPlayer(player_index, temp_player);
					keyboard.setCaps(true);
					keyboard.setIndex(0);
					player_index = 0;
					// Letter selector
					state = 3;
					consoleClear();
				}
				if (keyboard.processKeyboard(player_index)) {
					if (name_letters < 7) {
						temp_name[name_letters] = keyboard.getCharacter(keyboard.getIndex());
						name_letters++;
					}
					else printf("\x1b[8;27H--Max name length reached--");
				}
				else keyboard.printKeyboard();
				break;
			}
			break;
		case 3: // Choosing letter process
			if (keyboard.getCaps()) keyboard.setKeyboard(keyboard_1);
			else keyboard.setKeyboard(keyboard_2);

			switch (player_index) {
			case 0:
				printf("\x1b[4;24H--Choose your letter Player 1--");
				if (keyboard.processKeyboard(player_index)) {
					temp_player = map.getPlayer(player_index);
					temp_player.setLetter(keyboard.getCharacter(keyboard.getIndex()));
					map.modifyPlayer(player_index, temp_player);
					keyboard.setCaps(true);
					keyboard.setIndex(0);
					player_index = 1;
				}
				else keyboard.printKeyboard();
				break;
			default:
				printf("\x1b[4;24H--Choose your letter Player 2--");
				if (keyboard.processKeyboard(player_index)) {
					if (keyboard.getCharacter(keyboard.getIndex()) != temp_player.getLetter()) {
						temp_player = map.getPlayer(player_index);
						temp_player.setLetter(keyboard.getCharacter(keyboard.getIndex()));
						map.modifyPlayer(player_index, temp_player);
						keyboard.setCaps(true);
						keyboard.setIndex(0);
						player_index = 0;
						consoleClear();
						map.printMapFull(map.getPlayer(player_index));
						// Game process
						state = 4;
					}
					else printf("\x1b[7;27H\\|Letter already chosen|/");
				}
				else keyboard.printKeyboard();
				break;
			}
			break;
		case 4: // Game process
			// If bot players are alive
			if (map.getPlayer(player_index).getHealt() > 0 && map.getPlayer(player_index).getHealt() > 0) {
				// Player turn
				temp_player = map.getPlayer(player_index);

				if (map.processGame(temp_player, special, inventory_index, kDown)) {
					if (temp_player.getMoves() > 0) {
						temp_player.setMoves(temp_player.getMoves() - 1);
						map.modifyPlayer(player_index, temp_player);
					}
					else {
						next_player = true;
					}
					map.printMapOptimized(temp_player);
					// Next player turn
					if (next_player) {
						temp_player.setMoves(temp_player.getMaxMoves());
						temp_player.setLastMove(DIR_NULL);
						temp_player.setInventoryChanged(true);
						map.modifyPlayer(player_index, temp_player);
						switch (player_index)
						{
						case 0:
							player_index = 1;
							break;
						default:
							player_index = 0;
							break;
						}
						map.getPlayer(player_index).printStats();
						map.getPlayer(player_index).printInfo();
						map.getPlayer(player_index).printInventory();
						next_player = false;
					}
				}
				else map.modifyPlayer(player_index, temp_player);
			}
			else {
				restart(map);
				if (map.getPlayer(0).getHealt() <= 0) printWinner(1, map);
				else printWinner(0, map);

				state = 0;
			}
			break;
		default:
			break;
		}

		if (kDown & KEY_PLUS) {
			switch (state){
			case 0: // Main menu
				// Returns to HB menu
				active = false;
				break;
			case 1:
				consoleClear();
				state = 0;
				break;
			case 2:
			case 3:
				state = 0;
				restart(map);
				break;
			case 4:
				// Save Game
				state = 0;
				break;
			default:
				active = false;
				break;
			}
		}

		gfxFlushBuffers();
		gfxSwapBuffers();
		gfxWaitForVsync();
	}

	gfxExit();
	return 0;
}
