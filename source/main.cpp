//#define DEBUG

#include "Keyboard.h"
#include "Map.h"

void printControls() {
	consoleClear();
	printf(ANSI_COLOR_BOLDYELLOW "\x1b[3;27HReturn(+, -)" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_BOLDCYAN "\x1b[7;1H[Input] - Left Joycon (Horizontal)" ANSI_COLOR_RESET);
	printf("\x1b[9;1H[Keyboard]");
	printf("\x1b[11;3H-%c, %c, %c, %c, to control the keyboard", 24, 25, 26, 27);
	printf("\x1b[13;3H-SL for enter input and SR for switch caps");
	printf("\x1b[15;1H[Game]");
	printf("\x1b[17;3H-%c, %c, %c, %c, to control the character", 24, 25, 26, 27);
	printf("\x1b[19;3H-SL to select action (shoot/open) and %c, %c, %c, %c, to select the direction", 24, 25, 26, 27);
	printf("\x1b[21;3H-SL to use an object and SR to open inventory");
	printf(ANSI_COLOR_BOLDCYAN "\x1b[24;1H[Input] - Right Joycon (Horizontal)" ANSI_COLOR_RESET);
	printf("\x1b[26;1H[Keyboard]");
	printf("\x1b[28;3H-X,B,A,Y to control the keyboard");
	printf("\x1b[30;3H-SL for enter input and SR for switch caps");
	printf("\x1b[32;1H[Game]");
	printf("\x1b[34;3H-X,B,A,Y to control the character");
	printf("\x1b[36;3H-SR to select action (shoot/open) and X,B,A,Y to select the direction");
	printf("\x1b[38;3H-SR to use an object and SR to open inventory");
}
void printSettings(unsigned index, unsigned players, unsigned joycons) {
	if (index == 0) printf(ANSI_COLOR_WHITE);
	printf("\x1b[3;27HSave and return (+, -)" ANSI_COLOR_RESET);

	printf(ANSI_COLOR_CYAN "\x1b[6;27HPlayers: " ANSI_COLOR_BOLDCYAN "%d" ANSI_COLOR_RESET, players);
	if (index == 1) printf(ANSI_COLOR_BOLDGREEN);
	else printf(ANSI_COLOR_GREEN);
	printf("\x1b[8;30HAdd player" ANSI_COLOR_RESET);
	if (index == 2) printf(ANSI_COLOR_BOLDRED);
	else printf(ANSI_COLOR_RED);
	printf("\x1b[10;30HRemove player" ANSI_COLOR_RESET);

	if (index == 3) printf(ANSI_COLOR_BOLDMAGENTA);
	else printf(ANSI_COLOR_MAGENTA);
	printf("\x1b[13;27HChange controls" ANSI_COLOR_RESET);
	if (joycons == 0) printf(ANSI_COLOR_BOLDYELLOW);
	else printf(ANSI_COLOR_YELLOW);
	printf("\x1b[15;30H2 joycons for all" ANSI_COLOR_RESET);
	if (joycons == 1) printf(ANSI_COLOR_BOLDYELLOW);
	else printf(ANSI_COLOR_YELLOW);
	printf("\x1b[17;30H1 joycon per player" ANSI_COLOR_RESET);
	if (joycons == 2) printf(ANSI_COLOR_BOLDYELLOW);
	else printf(ANSI_COLOR_YELLOW);
	printf("\x1b[19;30H1 joycon for all" ANSI_COLOR_RESET);
}
void printMenu(unsigned index) {
	if (index == 0) printf(ANSI_COLOR_BOLDRED);
	else printf(ANSI_COLOR_RED);
	printf("\x1b[5;27HQuickplay" ANSI_COLOR_RESET);
	if (index == 1) printf(ANSI_COLOR_BOLDYELLOW);
	else printf(ANSI_COLOR_YELLOW);
	printf("\x1b[9;27HName selector" ANSI_COLOR_RESET);
	if (index == 2) printf(ANSI_COLOR_BOLDGREEN);
	else printf(ANSI_COLOR_GREEN);
	printf("\x1b[13;27HLoad saved game (not yet)" ANSI_COLOR_RESET);
	if (index == 3) printf(ANSI_COLOR_BOLDMAGENTA);
	else printf(ANSI_COLOR_MAGENTA);
	printf("\x1b[17;27HSettings" ANSI_COLOR_RESET);
	if (index == 4) printf(ANSI_COLOR_BOLDCYAN);
	else printf(ANSI_COLOR_CYAN);
	printf("\x1b[21;27HControls menu" ANSI_COLOR_RESET);
	if (index == 5) printf(ANSI_COLOR_WHITE);
	printf("\x1b[25;27HReturn to Homebrew menu (+, -)" ANSI_COLOR_RESET);
}
void printWinner(const Player &player) {
	unsigned i;

	player.printColor();
	printf("\x1b[29;30H--- ");
	for (i = 0;i < 8;i++) {
		printf("%c", player.getName(i));
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

	int name_letters = 0;
	int special = 0;

	unsigned i;
	unsigned state = 0;
	unsigned inventory_index = 0;
	unsigned menu_index = 0;
	unsigned settings_index = 0;
	unsigned player_index = 0;
	unsigned joycons_controls = 0; 
	
	Map map;
	Keyboard keyboard(keyboard_1);
	Player temp_player = map.getPlayer(0);

	unsigned players = map.getPlayers()+1;

	consoleInit(NULL);

	initJoycons();
	printMenu(0);
	// Main loop
	while (active)
	{
		//Scan all the inputs. This should be done once for each frame
		hidScanInput();

		u64 kDown = Input::getInputDown(0);
		u64 kDown_P2;
		u64 kDown_P3;
		u64 kDown_P4;
		u64 kDown_P5;
		u64 kDown_P6;
		u64 kDown_P7;
		u64 kDown_P8;

		switch (joycons_controls)
		{
		case 0:
			kDown_P2 = Input::getInputDown(1);
			kDown_P3 = Input::getInputDown(0);
			kDown_P4 = Input::getInputDown(1);
			kDown_P5 = Input::getInputDown(0);
			kDown_P6 = Input::getInputDown(1);
			kDown_P7 = Input::getInputDown(0);
			kDown_P8 = Input::getInputDown(1);
			break;
		case 1:
			kDown_P2 = Input::getInputDown(1);
			kDown_P3 = Input::getInputDown(2);
			kDown_P4 = Input::getInputDown(3);
			kDown_P5 = Input::getInputDown(4);
			kDown_P6 = Input::getInputDown(5);
			kDown_P7 = Input::getInputDown(6);
			kDown_P8 = Input::getInputDown(7);
			break;
		default:
			kDown_P2 = Input::getInputDown(0);
			kDown_P3 = Input::getInputDown(0);
			kDown_P4 = Input::getInputDown(0);
			kDown_P5 = Input::getInputDown(0);
			kDown_P6 = Input::getInputDown(0);
			kDown_P7 = Input::getInputDown(0);
			kDown_P8 = Input::getInputDown(0);
			break;
		}

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
		case 3:
			key = kDown_P4;
			break;
		case 4:
			key = kDown_P5;
			break;
		case 5:
			key = kDown_P6;
			break;
		case 6:
			key = kDown_P7;
			break;
		default:
			key = kDown_P8;
			break;
		}

		switch (state) {
		case 0: // Main menu
			if ((kDown | kDown_P2 | kDown_P3 | kDown_P4) & DOWN) {
				if (menu_index < 5) menu_index++;
				printMenu(menu_index);
			}
			if ((kDown | kDown_P2 | kDown_P3 | kDown_P4) & UP) {
				if (menu_index > 0) menu_index--;
				printMenu(menu_index);
			}
			if ((kDown | kDown_P2 | kDown_P3 | kDown_P4) & ACTION_1) {
				switch (menu_index)
				{
				case 0: // Quickplay
					consoleClear();
					map.setPlayers(players);
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
				case 3: // Settings
					consoleClear();
					printSettings(settings_index, players, joycons_controls);
					state = 5;
					break;
				case 4: // Print Controls
					state = 1;
					printControls();
					break;
				default: // Return HB menu
					active = false;
					break;
				}
				menu_index = 0;
			}
			break;
		case 1: // Controls menu
			if ((kDown | kDown_P2 | kDown_P3 | kDown_P4) & ACTION_1) {
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
					if (player_index < players-1) player_index++;
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
				if (player_index < players-1) {
					player_index++;
					consoleClear();
				}
				else {
					player_index = 0;
					consoleClear();
					map.setPlayers(players);
					map.printMapFull(map.getPlayer(player_index));
					// Game process
					state = 4;
				}
			}
			else keyboard.printKeyboard();
			break;
		case 4: // Game process
			#ifdef DEBUG
				printf(ANSI_COLOR_BOLDRED "\x1b[2;2HID: %d | Healt: %d 1 > 4?" ANSI_COLOR_RESET, map.getPlayer(player_index).getId(), map.getPlayer(player_index).getHealt());
				printf(ANSI_COLOR_BOLDRED "\x1b[3;2HPLAYERS: %d | INDEX: %u" ANSI_COLOR_RESET, map.getPlayers(), player_index);
			#endif // DEBUG
			// Player turn
			if (map.getPlayers() > 0) {
				for (i = 0; i <= map.getPlayers();i++) {
					if (map.getPlayer(i).getHealt() <= 0) {
						if (player_index > 0 && i < map.getPlayers()) player_index--;
						map.removePlayer(i);
					}
				}
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
						if (player_index < map.getPlayers()) player_index++;
						else player_index = 0;
						map.getPlayer(player_index).printStats();
						map.getPlayer(player_index).printInfo();
						map.getPlayer(player_index).printInventory();
						next_player = false;
					}
				}
				else map.modifyPlayer(player_index, temp_player);
			}
			else {
				temp_player = map.getPlayer(0);
				restart(map);
				printWinner(temp_player);
				state = 0;
				player_index = 0;
			}
			break;
		case 5: // Settings menu
			if ((kDown | kDown_P2 | kDown_P3 | kDown_P4) & DOWN) {
				if (settings_index < 3) settings_index++;
				printSettings(settings_index, players, joycons_controls);
			}
			if ((kDown | kDown_P2 | kDown_P3 | kDown_P4) & UP) {
				if (settings_index > 0) settings_index--;
				printSettings(settings_index, players, joycons_controls);
			}
			if ((kDown | kDown_P2 | kDown_P3 | kDown_P4) & ACTION_1) {
				switch (settings_index) {
				case 0:
					state = 0;
					consoleClear();
					printMenu(0);
					break;
				case 1:
					if(players < 8) players++;
					printSettings(settings_index, players, joycons_controls);
					break;
				case 2:
					if (players > 2) players--;
					printSettings(settings_index, players, joycons_controls);
					break;
				default:
					if (joycons_controls < 2) joycons_controls++;
					else joycons_controls = 0;
					printSettings(settings_index, players, joycons_controls);
					break;
				}
			}
			break;
		default:
			break;
		}

		if ((kDown | kDown_P2 | kDown_P3 | kDown_P4) & EXIT) {
			player_index = 0;
			switch (state){
			case 0: // Main menu
				// Returns to HB menu
				active = false;
				break;
			case 1: // Controls menu
				consoleClear();
				printMenu(0);
				state = 0;
				break;
			case 2: // Name selector
			case 3: // Letter selector
				state = 0;
				restart(map);
				break;
			case 4:
				// Save Game
				state = 0;
				restart(map);
				break;
			case 5:
				state = 0;
				consoleClear();
				printMenu(0);
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
