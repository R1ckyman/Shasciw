#include "Map.h"

#define MAP_X 27
#define MAP_Y 7

Map::Map() {
	unsigned i;
	unsigned y;
	playerCount = 4;
	Player player_1(1, 1, 0);
	Player player_2(30, 1, 1);
	players.push_back(player_1);
	players.push_back(player_2);

	char map[MAPSIZE][MAPSIZE] = {
	{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
	{'#',' ',' ',' ',' ','o','#','o','#','o',' ',' ',' ','o','#','o','o','#','o',' ',' ',' ','o','#','o','#','o',' ',' ',' ',' ','#'},
	{'#',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#',' ',' ','#',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#'},
	{'#','#','#',' ',' ',' ','D',' ','D',' ',' ',' ',' ',' ','#',' ',' ','#',' ',' ',' ',' ',' ','D',' ','D',' ',' ',' ','#','#','#'},
	{'#',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#',' ',' ','#',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#'},
	{'#','o',' ',' ',' ','o','#',' ','#','o',' ',' ',' ','o','#',' ',' ','#','o',' ',' ',' ','o','#',' ','#','o',' ',' ',' ','o','#'},
	{'#','#','#','#','D','#','#',' ','#','#','D','#','#','#','#',' ',' ','#','#','#','#','D','#','#',' ','#','#','D','#','#','#','#'},
	{'#','o',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','D',' ',' ','D',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','o','#'},
	{'#','#','#','#','D','#','#',' ','#','#','D','#','#','#','#',' ',' ','#','#','#','#','D','#','#',' ','#','#','D','#','#','#','#'},
	{'#','o',' ',' ',' ','o','#',' ','#','o',' ',' ',' ','o','#',' ',' ','#','o',' ',' ',' ','o','#',' ','#','o',' ',' ',' ','o','#'},
	{'#',' ',' ',' ',' ',' ','D',' ','D',' ',' ',' ',' ',' ','#','D','#','#',' ',' ',' ',' ',' ','D',' ','D',' ',' ',' ',' ',' ','#'},
	{'#',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ','#','#','#',' ','o','#','#','#',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#'},
	{'#',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#',' ',' ','#',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#'},
	{'#','o',' ',' ',' ','o','#',' ','#','o',' ',' ',' ',' ','#',' ',' ','#',' ',' ',' ',' ','o','#',' ','#','o',' ',' ',' ','o','#'},
	{'#','#','#','#','#','#','#','D','#','#','#','#','#','#','#','D','D','#','#','#','#','#','#','#','D','#','#','#','#','#','#','#'},
	{'#','o','#',' ',' ',' ','#',' ','D',' ','#',' ',' ',' ','#',' ',' ','D',' ','#',' ',' ',' ','#',' ','D',' ','#',' ',' ',' ','#'},
	{'#',' ',' ',' ','#',' ','D',' ','#',' ',' ',' ','#',' ','D',' ',' ','#',' ',' ',' ','#',' ','D',' ','#',' ',' ',' ','#','o','#'},
	{'#','#','#','#','#','#','#','D','#','#','#','#','#','#','#','D','D','#','#','#','#','#','#','#','D','#','#','#','#','#','#','#'},
	{'#','o',' ',' ',' ','o','#',' ','#','o',' ',' ',' ',' ','#',' ',' ','#',' ',' ',' ',' ','o','#',' ','#','o',' ',' ',' ','o','#'},
	{'#',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#',' ',' ','#',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#'},
	{'#',' ',' ',' ',' ',' ','D',' ','D',' ',' ',' ','#','#','#','o',' ','#','#','#',' ',' ',' ','D',' ','D',' ',' ',' ',' ',' ','#'},
	{'#',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#','#','D','#',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#'},
	{'#','o',' ',' ',' ',' ','#',' ','#','o',' ',' ',' ','o','#',' ',' ','#','o',' ',' ',' ','o','#',' ','#','o',' ',' ',' ','o','#'},
	{'#','#','#','#','D','#','#',' ','#','#','D','#','#','#','#',' ',' ','#','#','#','#','D','#','#',' ','#','#','D','#','#','#','#'},
	{'#','o',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','D',' ',' ','D',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','o','#'},
	{'#','#','#','#','D','#','#',' ','#','#','D','#','#','#','#',' ',' ','#','#','#','#','D','#','#',' ','#','#','D','#','#','#','#'},
	{'#','o',' ',' ',' ','o','#',' ','#','o',' ',' ',' ','o','#',' ',' ','#','o',' ',' ',' ','o','#',' ','#','o',' ',' ',' ','o','#'},
	{'#',' ',' ',' ',' ',' ','D',' ','D',' ',' ',' ',' ',' ','#',' ',' ','#',' ',' ',' ',' ',' ','D',' ','D',' ',' ',' ',' ',' ','#'},
	{'#','#','#',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#',' ',' ','#',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ','#','#','#'},
	{'#',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#',' ',' ','#',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#'},
	{'#',' ',' ',' ',' ','o','#','o','#','o',' ',' ',' ','o','#','o','o','#','o',' ',' ',' ','o','#','o','#','o',' ',' ',' ',' ','#'},
	{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}
	};
	// Random class
	std::mt19937 mt(time(NULL));
	std::uniform_int_distribution<unsigned> distribution(0, 7);
	for (i = 0;i < MAPSIZE;i++) {
		for (y = 0;y < MAPSIZE;y++) {
			terrain[i][y] = map[i][y];
			if (terrain[i][y] == 'D') {
				Door door(i, y);
				doors.push_back(door);
			}
			if (terrain[i][y] == 'o') {
				unsigned id = distribution(mt);
				Object object(i, y, id);
				objects.push_back(object);
			}
		}
	}
}
void Map::removePlayer(unsigned player) {
	for (unsigned i = 0;i < players.size();i++) {
		if (i == player) {
			terrain[players[i].getY()][players[i].getX()] = ' ';
			printf("\x1b[%d;%dH ", players[i].getY() + MAP_Y, players[i].getX() + MAP_X);
			players.erase(players.begin() + i);
			break;
		}
	}
}

void Map::modifyPlayer(unsigned player_index, Player player) {
	players[player_index] = player;
}
void Map::modifyBullet(unsigned position, Bullet bullet) {
	bullets[position] = bullet;
}
void Map::setPlayers(unsigned playerCount) {
	Player player_3(1, 30, 2);
	Player player_4(30, 30, 3);
	Player player_5(13, 13, 4);
	Player player_6(18, 13, 5);
	Player player_7(13, 18, 6);
	Player player_8(18, 18, 7);

	this->playerCount = playerCount;
	if (playerCount >= 3) {
		players.push_back(player_3);
		if (playerCount >= 4) {
			players.push_back(player_4);
			if (playerCount >= 5) {
				players.push_back(player_5);
				if (playerCount >= 6) {
					players.push_back(player_6);
					if (playerCount >= 7) {
						players.push_back(player_7);
						if (playerCount >= 8) {
							players.push_back(player_8);
						}
					}
				}
			}
		}
	}
}
Player Map::getPlayer(unsigned player) const {
	return players[player];
}
int Map::getDoorPosition(unsigned x, unsigned y) const {
	unsigned i;

	for (i = 0; i < doors.size(); i++) {
		if (doors[i].getX() == x && doors[i].getY() == y) {
			return i;
		}
	}
	return -1;
}
int Map::getObjectPosition(unsigned x, unsigned y) const {
	unsigned i;

	for (i = 0; i < objects.size(); i++) {
		if (objects[i].getX() == x && objects[i].getY() == y) {
			return i;
		}
	}
	return -1;
}
void Map::printMapOptimized(Player player) {
	unsigned i;

	terrain[player.getY()][player.getX()] = player.getLetter();

	player.printInfo();

	//Player control
	player.printColor();
	switch (player.getLastMove()) {
	case DIR_UP:
		printf("\x1b[%d;%dH%c", player.getY() + MAP_Y, player.getX() + MAP_X, player.getLetter());
		printf("\x1b[%d;%dH ", player.getY() + MAP_Y + 1, player.getX() + MAP_X);
		break;
	case DIR_DOWN:
		printf("\x1b[%d;%dH%c", player.getY() + MAP_Y, player.getX() + MAP_X, player.getLetter());
		printf("\x1b[%d;%dH ", player.getY() + MAP_Y - 1, player.getX() + MAP_X);
		break;
	case DIR_LEFT:
		printf("\x1b[%d;%dH%c", player.getY() + MAP_Y, player.getX() + MAP_X, player.getLetter());
		printf("\x1b[%d;%dH ", player.getY() + MAP_Y, player.getX() + MAP_X + 1);
		break;
	case DIR_RIGHT:
		printf("\x1b[%d;%dH%c", player.getY() + MAP_Y, player.getX() + MAP_X, player.getLetter());
		printf("\x1b[%d;%dH ", player.getY() + MAP_Y, player.getX() + MAP_X - 1);
		break;
	default:
		printf("\x1b[%d;%dH%c", player.getY() + MAP_Y, player.getX() + MAP_X, player.getLetter());
		break;
	}

	// Bullet control
	printf(ANSI_COLOR_BOLDRED);
	for (i = 0;i < bullets.size();i++) {
		if (processBullet(i, bullets[i])) {
			bullets.erase(bullets.begin() + i);
			i--;
		}
		else {
			printf("\x1b[%d;%dH*", bullets[i].getY() + MAP_Y, bullets[i].getX() + MAP_X);
		}
	}
	
	printf(ANSI_COLOR_MAGENTA);
	//Door control
	for (i = 0;i < doors.size();i++) {
		if (doors[i].getOpen()) {
			doors[i].setTime();
			if (doors[i].getTime() == 0 && terrain[doors[i].getX()][doors[i].getY()] == 'D') {
				printf("\x1b[%d;%dHD", doors[i].getX() + MAP_Y, doors[i].getY() + MAP_X);
				doors[i].setOpen(false);
			}
			else if (terrain[doors[i].getX()][doors[i].getY()] == 'D') {
				printf("\x1b[%d;%dH_", doors[i].getX() + MAP_Y, doors[i].getY() + MAP_X);
			}
		}
	}
	printf(ANSI_COLOR_RESET);
}
void Map::printMapFull(Player player) {
	unsigned i;
	unsigned y;

	for (i = 0; i < players.size();i++) terrain[players[i].getY()][players[i].getX()] = players[i].getLetter();

	for (i = 0;i < MAPSIZE;i++) {
		printf("\x1b[%d;%dH", i + MAP_Y, MAP_X);
		for (y = 0;y < MAPSIZE;y++) {
			if (i == players[0].getY() && y == players[0].getX()) printf(ANSI_COLOR_BOLDYELLOW "%c" ANSI_COLOR_RESET, players[0].getLetter());
			else if (i == players[1].getY() && y == players[1].getX()) printf(ANSI_COLOR_BOLDGREEN "%c" ANSI_COLOR_RESET, players[1].getLetter());
			else if (playerCount >= 2 && i == players[2].getY() && y == players[2].getX()) printf(ANSI_COLOR_BOLDMAGENTA "%c" ANSI_COLOR_RESET, players[2].getLetter());
			else if (playerCount >= 3 && i == players[3].getY() && y == players[3].getX()) printf(ANSI_COLOR_BOLDCYAN "%c" ANSI_COLOR_RESET, players[3].getLetter());
			else if (playerCount >= 4 && i == players[4].getY() && y == players[4].getX()) printf(ANSI_COLOR_BOLDRED "%c" ANSI_COLOR_RESET, players[4].getLetter());
			else if (playerCount >= 5 && i == players[5].getY() && y == players[5].getX()) printf(ANSI_COLOR_YELLOW "%c" ANSI_COLOR_RESET, players[5].getLetter());
			else if (playerCount >= 6 && i == players[6].getY() && y == players[6].getX()) printf(ANSI_COLOR_GREEN "%c" ANSI_COLOR_RESET, players[6].getLetter());
			else if (playerCount >= 7 && i == players[7].getY() && y == players[7].getX()) printf(ANSI_COLOR_RED "%c" ANSI_COLOR_RESET, players[7].getLetter());
			else if (playerCount >= 8 && i == players[8].getY() && y == players[8].getX()) printf(ANSI_COLOR_CYAN "%c" ANSI_COLOR_RESET, players[8].getLetter());
			else if (terrain[i][y] == 'O' || terrain[i][y] == 'o') printf(ANSI_COLOR_CYAN "%c" ANSI_COLOR_RESET, terrain[i][y]);
			else if (terrain[i][y] == 'D') printf(ANSI_COLOR_MAGENTA "%c" ANSI_COLOR_RESET, terrain[i][y]);
			else printf("%c", terrain[i][y]);
		}
		printf("\n");
	}
	player.printStats();
	player.printInventory();
	player.printInfo();
}
bool Map::processMovement(Player &player, Dir dir) {
	bool movement = false;
	switch (dir) {
	case DIR_UP:
		if (terrain[player.getY() - 1][player.getX()] == ' ' || (terrain[player.getY() - 1][player.getX()] == 'D' && doors[getDoorPosition(player.getY() - 1, player.getX())].getOpen())) {
			if (getDoorPosition(player.getY(), player.getX()) != -1) terrain[player.getY()][player.getX()] = 'D';
			else terrain[player.getY()][player.getX()] = ' ';
			player.setY(player.getY() - 1);
			player.setLastMove(DIR_UP);
			movement = true;
		}
		else if (terrain[player.getY() - 1][player.getX()] == 'o') {
			int position = getObjectPosition(player.getY() - 1, player.getX());
			if (player.addObject(objects[position].getId())) {
				objects.erase(objects.begin() + position);
				terrain[player.getY()][player.getX()] = ' ';
				player.setY(player.getY() - 1);
				player.setLastMove(DIR_UP);
				player.setInventoryChanged(true);
				movement = true;
			}
		}
		break;
	case DIR_DOWN:
		if (terrain[player.getY() + 1][player.getX()] == ' ' || (terrain[player.getY() + 1][player.getX()] == 'D' && doors[getDoorPosition(player.getY() + 1, player.getX())].getOpen())) {
			if (getDoorPosition(player.getY(), player.getX()) != -1) terrain[player.getY()][player.getX()] = 'D';
			else terrain[player.getY()][player.getX()] = ' ';
			player.setY(player.getY() + 1);
			player.setLastMove(DIR_DOWN);
			movement = true;
		}
		else if (terrain[player.getY() + 1][player.getX()] == 'o') {
			int position = getObjectPosition(player.getY() + 1, player.getX());
			if (player.addObject(objects[position].getId())) {
				objects.erase(objects.begin() + position);
				terrain[player.getY()][player.getX()] = ' ';
				player.setY(player.getY() + 1);
				player.setLastMove(DIR_DOWN);
				player.setInventoryChanged(true);
				movement = true;
			}
		}
		break;
	case DIR_LEFT:
		if (terrain[player.getY()][player.getX() - 1] == ' ' || (terrain[player.getY()][player.getX() - 1] == 'D' && doors[getDoorPosition(player.getY(), player.getX() - 1)].getOpen())) {
			if (getDoorPosition(player.getY(), player.getX()) != -1) terrain[player.getY()][player.getX()] = 'D';
			else terrain[player.getY()][player.getX()] = ' ';
			player.setX(player.getX() - 1);
			player.setLastMove(DIR_LEFT);
			movement = true;
		}
		else if (terrain[player.getY()][player.getX() - 1] == 'o') {
			int position = getObjectPosition(player.getY(), player.getX() - 1);
			if (player.addObject(objects[position].getId())) {
				objects.erase(objects.begin() + position);
				terrain[player.getY()][player.getX()] = ' ';
				player.setX(player.getX() - 1);
				player.setLastMove(DIR_LEFT);
				player.setInventoryChanged(true);
				movement = true;
			}
		}
		break;
	case DIR_RIGHT:
		if (terrain[player.getY()][player.getX() + 1] == ' ' || (terrain[player.getY()][player.getX() + 1] == 'D' && doors[getDoorPosition(player.getY(), player.getX() + 1)].getOpen())) {
			if (getDoorPosition(player.getY(), player.getX()) != -1) terrain[player.getY()][player.getX()] = 'D';
			else terrain[player.getY()][player.getX()] = ' ';
			player.setX(player.getX() + 1);
			player.setLastMove(DIR_RIGHT);
			movement = true;
		}
		else if (terrain[player.getY()][player.getX() + 1] == 'o') {
			int position = getObjectPosition(player.getY(), player.getX() + 1);
			if (player.addObject(objects[position].getId())) {
				objects.erase(objects.begin() + position);
				terrain[player.getY()][player.getX()] = ' ';
				player.setX(player.getX() + 1);
				player.setLastMove(DIR_RIGHT);
				player.setInventoryChanged(true);
				movement = true;
			}
		}
		break;
	default:
		break;
	}
	return movement;
}
bool Map::processGame(Player &player, int &special, unsigned &index, u64 kDown) {
	bool action = false;
	bool movement = false;

	int position;

	//Specials keys
	if (kDown & ACTION_1) {
		switch (special) {
		case 0:
			special = 2;
			break;
		case 1:
			switch (player.getObject(index)) {
			case 0:
				player.setMoves(player.getMoves() + 2);
				break;
			case 1:
				player.setMoves(player.getMoves() + 3);
				break;
			case 2:
				player.setMoves(player.getMoves() + 4);
				break;
			case 3:
				player.setMaxMoves(player.getMaxMoves() + 1);
				break;
			case 4:
				player.setMaxMoves(player.getMaxMoves() + 2);
				break;
			case 5:
				player.setDamage(player.getDamage() + 1);
				break;
			case 6:
				player.setHealt(player.getHealt() + 1);
				break;
			case 7:
				player.setHealt(player.getHealt() + 2);
				break;
			default:
				break;
			}
			special = 0;
			index = 11;
			player.setStatsChanged(true);
			player.printInventory();
			break;
		case 2:
			special = 0;
			break;
		default:
			break;
		}
	}
	// Open close inventory (ZL & ZR)
	if (kDown & ACTION_2) {
		switch (special) {
		case 0:
			player.setInventoryChanged(true);
			special = 1;
			index = 0;
			break;
		case 1:
			special = 0;
			player.printInventory();
			break;
		default:
			break;
		}
	}
	//Directions
	// Up
	if (kDown & UP) {
		switch (special) {
		case 0:
			movement = processMovement(player, DIR_UP);
			break;
		case 1:
			if (index > 0) {
				index--;
				player.setInventoryChanged(true);
			}
			break;
		case 2:
			position = getDoorPosition(player.getY() - 1, player.getX());
			if (position != -1 && !doors[position].getOpen()) {
				action = true;
				doors[position].setOpen(true);
			}
			else if (terrain[player.getY() - 1][player.getX()] == ' ') {
				Bullet temp_bullet(player.getX(), player.getY(), DIR_UP, player.getId(), player.getDamage());
				bullets.push_back(temp_bullet);
				action = true;
			}
			break;
		default:
			break;
		}
	}
	// Down
	if (kDown & DOWN) {
		switch (special) {
		case 0:
			movement = processMovement(player, DIR_DOWN);
			break;
		case 1:
			if (index < player.getInventorySize() - 1) {
				player.setInventoryChanged(true);
				index++;
			}
			break;
		case 2:
			position = getDoorPosition(player.getY() + 1, player.getX());
			if (position != -1 && !doors[position].getOpen()) {
				action = true;
				doors[position].setOpen(true);
			}
			else if (terrain[player.getY() + 1][player.getX()] == ' ') {
				Bullet temp_bullet(player.getX(), player.getY(), DIR_DOWN, player.getId(), player.getDamage());
				bullets.push_back(temp_bullet);
				action = true;
			}
			break;
		default:
			break;
		}
	}
	// Left
	if (kDown & LEFT) {
		switch (special) {
		case 0:
			movement = processMovement(player, DIR_LEFT);
			break;
		case 1:
			break;
		case 2:
			position = getDoorPosition(player.getY(), player.getX() - 1);
			if (position != -1 && !doors[position].getOpen()) {
				doors[position].setOpen(true);
				action = true;
			}
			else if (terrain[player.getY()][player.getX() - 1] == ' ') {
				Bullet temp_bullet(player.getX(), player.getY(), DIR_LEFT, player.getId(), player.getDamage());
				bullets.push_back(temp_bullet);
				action = true;
			}
			break;
		default:
			break;
		}
	}
	// Right
	if (kDown & RIGHT) {
		switch (special) {
		case 0:
			movement = processMovement(player, DIR_RIGHT);
			break;
		case 2:
			position = getDoorPosition(player.getY(), player.getX() + 1);
			if (position != -1 && !doors[position].getOpen()) {
				doors[position].setOpen(true);
				action = true;
			}
			else if (terrain[player.getY()][player.getX() + 1] == ' ') {
				Bullet temp_bullet(player.getX(), player.getY(), DIR_RIGHT, player.getId(), player.getDamage());
				bullets.push_back(temp_bullet);
				action = true;
			}
			break;
		default:
			break;
		}
	}

	if (player.getInventoryChanged()) {
		player.setInventoryChanged(false);
		if (special == 0) index = 11;
		player.printInventory(index);
	}
	if (player.getStatsChanged()) {
		player.setStatsChanged(false);
		player.printStats();
		player.printInfo();
	}
	if (!movement) player.setLastMove(DIR_NULL);
	if (action || movement) special = 0;

	switch (special) {
	case 0:
		printf("\x1b[7;60H|Normal movement| ");
		break;
	case 1:
		printf("\x1b[7;60H" ANSI_COLOR_BOLDGREEN "|Inventory opened|" ANSI_COLOR_RESET "\x1b[0m");
		break;
	case 2:
		printf("\x1b[7;60H" ANSI_COLOR_BOLDCYAN "|Action selected| " ANSI_COLOR_RESET "\x1b[0m");
		break;
	default:
		break;
	}
	return (action || movement);
}
void Map::playerHit(unsigned player, const Bullet &bullet) {
	Player temp_player = players[0];
	
	switch (player) {
	case 0:
		temp_player = players[0];
		break;
	case 1:
		temp_player = players[1];
		break;
	case 2:
		temp_player = players[2];
		break;
	default:
		temp_player = players[3];
		break;
	}

	temp_player.setHealt(temp_player.getHealt() - bullet.getDamage());
	temp_player.setStatsChanged(true);
	modifyPlayer(player, temp_player);
}
bool Map::bulletHit(const Bullet &bullet, Dir dir) {
	for(unsigned i = 0; i < players.size(); i++)
		switch (dir) {
		case DIR_UP:
			if (bullet.getY() - 1 == players[i].getY() && bullet.getX() == players[i].getX()) {
				playerHit(i, bullet);
				return true;
			}
			break;
		case DIR_DOWN:
			if (bullet.getY() + 1 == players[i].getY() && bullet.getX() == players[i].getX()) {
				playerHit(i, bullet);
				return true;
			}
			break;
		case DIR_RIGHT:
			if (bullet.getY() == players[i].getY() && bullet.getX() + 1 == players[i].getX()) {
				playerHit(i, bullet);
				return true;
			}
			break;
		case DIR_LEFT:
			if (bullet.getY() == players[i].getY() && bullet.getX() -1 == players[i].getX()) {
				playerHit(i, bullet);
				return true;
			}
			break;
		case DIR_NULL:
			if (bullet.getPlayer() != players[i].getId() && bullet.getY() == players[i].getY() && bullet.getX() == players[i].getX()) {
				playerHit(i, bullet);
				return true;
			}
			break;
		default:
			return true;
			break;
		}
	return false;
}
bool Map::processBullet(unsigned i, Bullet bullet) {
	if (bulletHit(bullet, DIR_NULL)) return true;
	if (terrain[bullet.getY()][bullet.getX()] == ' ') printf("\x1b[%d;%dH ", bullet.getY() + MAP_Y, bullet.getX() + MAP_X);
	switch (bullet.getDir()) {
	case DIR_UP:
		if (terrain[bullet.getY() - 1][bullet.getX()] == ' ') {
			bullet.setY(bullet.getY() - 1);
			modifyBullet(i, bullet);
		}
		else if (bulletHit(bullet, DIR_UP)) return true;
		else return true;
		break;
	case DIR_DOWN:
		if (terrain[bullet.getY() + 1][bullet.getX()] == ' ') {
			bullet.setY(bullet.getY() + 1);
			modifyBullet(i, bullet);
		}
		else if (bulletHit(bullet, DIR_DOWN)) return true;
		else return true;
		break;
	case DIR_RIGHT:
		if (terrain[bullet.getY()][bullet.getX() + 1] == ' ') {
			bullet.setX(bullet.getX() + 1);
			modifyBullet(i, bullet);
		}
		else if (bulletHit(bullet, DIR_RIGHT)) return true;
		else return true;
		break;
	case DIR_LEFT:
		if (terrain[bullet.getY()][bullet.getX() - 1] == ' ') {
			bullet.setX(bullet.getX() - 1);
			modifyBullet(i, bullet);
		}
		else if (bulletHit(bullet, DIR_LEFT)) return true;
		else return true;
		break;
	default:
		return true;
	}
	return false;
}