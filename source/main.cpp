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
void printMenu(unsigned index) {
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
	printf("\x1b[25;30H--- ");
	for (i = 0;i < 8;i++) {
		printf("%c", map.getPlayer(player).getName(i));
	}
	printf(" won---" ANSI_COLOR_RESET);

	printMenu(0);
}
void restart(Map &map) {
	Map temp_map;
	map = temp_map;
	consoleClear();
	printMenu(0);
}
void initJoycons() {
	hidSetNpadJoyHoldType(HidJoyHoldType_Horizontal);
	for (int id = 0; id < 8; id++) {
		hidSetNpadJoyAssignmentModeSingleByDefault((HidControllerID)id);
	}
	hidScanInput();
	for (int id = 0; id < 8; id++) {
		HidControllerType type = hidGetControllerType((HidControllerID)id);
		if (type == TYPE_JOYCON_LEFT)
			hidSetControllerLayout((HidControllerID)id, LAYOUT_LEFT);
		if (type == TYPE_JOYCON_RIGHT)
			hidSetControllerLayout((HidControllerID)id, LAYOUT_RIGHT);
	}
}
int main(int argc, char **argv)
{
	char keyboard_1[KEYBOARDSIZE] = { '0','1','2','3','4','5','6','7','8','9',
									'A','B','C','D','E','F','G','H','I','J',
									'K','L','M','N','O','P','Q','R','S','T',
									'U','V','W','X','Y','Z','$','/','@',' ',
									'\n','\\' };

	char keyboard_2[KEYBOARDSIZE] = { '&','%','?','!','=','+','(',')','[',']',
									'a','b','c','d','e','f','g','h','i','j',
									'k','l','m','n','o','p','q','r','s','t',
									'u','v','w','x','y','z','<','>','*',' ',
									'\n','\\' };

	char temp_name[8] = { '\0','\0','\0','\0','\0','\0','\0','\0' };

	bool active = true;
	bool next_player = false;

	char letter;

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

	consoleInit(NULL);

	initJoycons();
	printMenu(0);
	// Main loop
	while (active)
	{
		//Scan all the inputs. This should be done once for each frame
		hidScanInput();

		u64 kDown = Input::getInputDown(0);
		u64 kDown_P2 = Input::getInputDown(1);
		u64 kDown_P3 = Input::getInputDown(3);
		u64 kDown_P4 = Input::getInputDown(4);

		u64 key;
		switch (player_index){
		case 0:
			key = kDown;
			break;
		case 1:
			key = kDown_P2;
			break;
		case 2:
			key = kDown_P3;
			break;
		default:
			key = kDown_P4;
			break;
		}

		switch (state) {
		case 0: // Main menu
			if ((kDown | kDown_P2) & DOWN) {
				if (menu_index < 4) menu_index++;
				printMenu(menu_index);
			}
			if ((kDown | kDown_P2) & UP) {
				if (menu_index > 0) menu_index--;
				printMenu(menu_index);
			}
			if ((kDown | kDown_P2) & ACTION_1) {
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
				case 2: // Load Game
					printMenu(0);
					break;
				case 3: // Print Controls
					state = 1;
					printControls();
					break;
				default: // Return HB menu
					active = false;
					break;
				}
				menu_index = 0;
			}
			if ((kDown | kDown_P2) & SPECIAL_1) {
				consoleClear();
				map.printMapFull(map.getPlayer(player_index));
				state = 4;
			}
			break;
		case 1: // Controls menu
			if ((kDown | kDown_P2) & ACTION_1) {
				consoleClear();
				printMenu(0);
				state = 0;
			}
			break;
		case 2: // Choosing name process
			if (keyboard.getCaps()) keyboard.setKeyboard(keyboard_1);
			else keyboard.setKeyboard(keyboard_2);

			keyboard.printCurName(temp_name, name_letters);
			if (keyboard.processKeyboard(key)) {
				letter = keyboard.getCharacter(keyboard.getIndex());
				switch (letter) {
				case '\\': // Confirm
					temp_player = map.getPlayer(player_index);
					temp_player.setName(temp_name);
					map.modifyPlayer(player_index, temp_player);
					keyboard.setCaps(true);
					keyboard.setIndex(0);
					if (player_index == 0) player_index = 1;
					else {
						player_index = 0;
						state = 3; // Letter selector
						consoleClear();
					}
					name_letters = 0;
					consoleClear();
					for (i = 0;i < 8;i++) temp_name[i] = '\0';
					break;
				case '\n': // Delete
					if (name_letters > 0) {
						name_letters--;
						temp_name[name_letters] = '\0';
					}
					break;
				default:
					if (name_letters < 7) {
						temp_name[name_letters] = letter;
						name_letters++;
					}
					else printf(ANSI_COLOR_BOLDRED "\x1b[10;25H--Max name length reached--" ANSI_COLOR_RESET);
					break;
				}
			}
			else keyboard.printKeyboard();
			break;
		case 3: // Choosing letter process
			if (keyboard.getCaps()) keyboard.setKeyboard(keyboard_1);
			else keyboard.setKeyboard(keyboard_2);

			printf("\x1b[6;23H--Choose your letter Player %u--", player_index+1);
			if (keyboard.processKeyboard(key)) {
				if (keyboard.getIndex() > 39) {
					printf(ANSI_COLOR_BOLDRED "\x1b[10;27H\\|That isn't a letter|/" ANSI_COLOR_RESET);
					break;
				}
				letter = keyboard.getCharacter(keyboard.getIndex());
				temp_player = map.getPlayer(player_index);
				temp_player.setLetter(letter);
				map.modifyPlayer(player_index, temp_player);
				keyboard.setCaps(true);
				keyboard.setIndex(0);
				switch (player_index) {
				case 0:
					player_index = 1;
					consoleClear();
					break;
				default:
					player_index = 0;
					consoleClear();
					map.printMapFull(map.getPlayer(player_index));
					// Game process
					state = 4;
					break;
				}
			}
			else keyboard.printKeyboard();
			break;
		case 4: // Game process
			// If bot players are alive
			if (map.getPlayer(player_index).getHealt() > 0 && map.getPlayer(player_index).getHealt() > 0) {
				// Player turn
				temp_player = map.getPlayer(player_index);

				if (map.processGame(temp_player, special, inventory_index, key)) {
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

		if ((kDown | kDown_P2) & EXIT) {
			player_index = 0;
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
				restart(map);
				break;
			default:
				active = false;
				break;
			}
		}

		consoleUpdate(NULL);
	}

	consoleExit(NULL);
	hidMergeSingleJoyAsDualJoy((HidControllerID)0, (HidControllerID)1);
	return 0;
}
