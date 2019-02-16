#include "Map.h"

Map::Map() {
	unsigned i;
	unsigned y;
	char name_1[8] = { 'P','l','a','y','e','r','1','\0' };
	char name_2[8] = { 'P','l','a','y','e','r','2','\0' };
	Player player_1(name_1, 2, 12, 0);
	Player player_2(name_2, 13, 1, 1);
	char map[MAPSIZE][MAPSIZE] = {
	{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
	{'#','#','#','#','#','o',' ',' ',' ',' ','D',' ',' ',' ','#','#','o',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','#','o','#','#','#'},
	{'#','#','#','#','#',' ',' ','#','#','#','#',' ',' ','#','#','#','#',' ',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ','#','#','#'},
	{'#','#','#','#','#','#','D','#','#','#','#','#',' ','#','o','#','#','#','#','#','#','#','#','#','D','#','#','#','#','#','#','#'},
	{'#','#','#','#','#','#',' ','#','#',' ','o','#','o','#',' ','D',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
	{'#','o',' ',' ','D',' ',' ','o','#',' ',' ','D',' ','#',' ','#','#','#','#','#','#','#','#','#','D','#','#','#','#','#',' ','#'},
	{'#',' ',' ',' ','#','#','#','#','#',' ',' ','#',' ',' ',' ','#','#','#','o',' ',' ','#','#','#',' ','#','#','#','#','#',' ','#'},
	{'#',' ','o',' ',' ','#','#','#','#',' ',' ','#','D','#',' ','#','#','#',' ','#',' ','#','#','#',' ','#','#','o','#','#',' ','#'},
	{'#',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ','#','#','#',' ','#',' ',' ',' ','#',' ','#','#',' ','#','#',' ','#'},
	{'#',' ','#',' ',' ',' ',' ','#',' ',' ',' ','o',' ','#',' ','#','#','#',' ','#',' ','#',' ','D',' ','D',' ',' ',' ','D',' ','#'},
	{'#',' ','#','#',' ','o','#','#','#',' ',' ','#','#','#','D','#','#','#','o',' ',' ','#','#','#',' ','#','#',' ','#','#',' ','#'},
	{'#',' ',' ','D',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','o','#','#','#','#','#','#','#','#','#',' ','#','#','o','#','#',' ','#'},
	{'#',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ',' ','#',' ',' ',' ','#','#','#','#','#','D','#','#','#','#','#',' ','#'},
	{'#',' ',' ',' ',' ',' ','#',' ',' ',' ','o','#',' ','o',' ','D',' ',' ',' ','D',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
	{'#',' ',' ','#','o',' ','D',' ',' ',' ',' ','#','o',' ',' ','#',' ',' ',' ','#','#','#','#','#','D','#','#','#','#','#',' ','#'},
	{'#','#','#','#','#','#','#','#','D','#','#','#','#','#','D','#','#','o','#','#','#','#','#','#',' ','#','#','#','#','#',' ','#'},
	{'#','o','#',' ',' ',' ',' ',' ',' ','#','o',' ','#','#',' ','#','#','#','#','#','#','#','#','#',' ','#','#','#','#','o',' ','#'},
	{'#',' ','#','#',' ','#',' ','#','#','#',' ',' ','#','#',' ','#','#','#','#','o','#','#','#','#',' ','#','#','#','#','#',' ','#'},
	{'#',' ',' ','#',' ',' ',' ',' ',' ','D',' ',' ','#','#',' ','#','#','#',' ',' ',' ','#','#','#','D','#','#','#','#','#',' ','#'},
	{'#',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#','D','#','#','#',' ',' ',' ','#',' ',' ',' ',' ',' ','#','#','#',' ','#'},
	{'#','D','#',' ','#','#',' ',' ','D',' ',' ',' ','#',' ',' ',' ','o','#',' ',' ',' ','#',' ','#','#','#',' ','#','#','#',' ','#'},
	{'#',' ','#',' ',' ','#','o',' ','#',' ',' ',' ','#',' ','#','#',' ','#','#','D','#','#',' ','#','#','#',' ','#','#','#',' ','#'},
	{'#',' ','#',' ','o','#',' ',' ','#','o',' ',' ','D',' ','o','#',' ','D',' ',' ',' ',' ',' ','#','#','#',' ','D',' ','D',' ','#'},
	{'#',' ','#','#','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#','D','#','#',' ','#','#','o',' ','#','#','#',' ','#'},
	{'#',' ',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#',' ','#','#',' ',' ',' ',' ',' ','#','#','#',' ','#'},
	{'#','o','#','D','#','#','#','#',' ','#','#','#','#','#','#','D','#','#','#',' ','#','#','#','#','D','#','#','#','#','#',' ','#'},
	{'#','#',' ',' ','#','#','#','o',' ',' ','#','#','#','#','#',' ','#','#','#',' ','#','#','#','#',' ','#','#','#','#','#',' ','#'},
	{'#',' ',' ',' ','#','#','#','#',' ','#','#','#','#','#','#',' ','#','#','o',' ','o','#','#','#',' ','#','#',' ',' ',' ',' ','#'},
	{'#',' ',' ',' ','#','#','#','#',' ','#','#','#','#','#','#',' ','#','#','#',' ','#','#','#','#',' ','#','#',' ',' ','#','#','#'},
	{'#',' ',' ',' ','#','o','#','#','D','#','#','#','#','#','#',' ','#','#','#','D','#','#','#','#','D','#','#','#',' ','#','o','#'},
	{'#','#',' ',' ','D',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
	{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}
	};
	// Random class
	std::mt19937 mt(time(NULL));
	std::uniform_int_distribution<unsigned> distribution(0, 4);
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

	players.push_back(player_1);
	players.push_back(player_2);
}
void Map::modifyPlayer(unsigned player_index, Player player) {
	switch (player_index)
	{
	case 0:
		players[0] = player;
		break;
	default:
		players[1] = player;
		break;
	}
}
void Map::modifyBullet(unsigned position, Bullet bullet) {
	bullets[position] = bullet;
}
Player Map::getPlayer(unsigned player) const {
	switch (player)
	{
	case 0:
		return players[0];
		break;
	default:
		return players[1];
		break;
	}
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
	switch (player.getId()) {
	case 0:
		printf(ANSI_COLOR_BOLDYELLOW);
		break;
	default:
		printf(ANSI_COLOR_BOLDGREEN);
		break;
	}
	switch (player.getLastMove()) {
	case DIR_UP:
		printf("\x1b[%d;%dH%c", player.getY() + 7, player.getX() + 26, player.getLetter());
		printf("\x1b[%d;%dH ", player.getY() + 7 + 1, player.getX() + 26);
		break;
	case DIR_DOWN:
		printf("\x1b[%d;%dH%c", player.getY() + 7, player.getX() + 26, player.getLetter());
		printf("\x1b[%d;%dH ", player.getY() + 7 - 1, player.getX() + 26);
		break;
	case DIR_LEFT:
		printf("\x1b[%d;%dH%c", player.getY() + 7, player.getX() + 26, player.getLetter());
		printf("\x1b[%d;%dH ", player.getY() + 7, player.getX() + 26 + 1);
		break;
	case DIR_RIGHT:
		printf("\x1b[%d;%dH%c", player.getY() + 7, player.getX() + 26, player.getLetter());
		printf("\x1b[%d;%dH ", player.getY() + 7, player.getX() + 26 - 1);
		break;
	default:
		printf("\x1b[%d;%dH%c", player.getY() + 7, player.getX() + 26, player.getLetter());
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
			printf("\x1b[%d;%dH*", bullets[i].getY() + 7, bullets[i].getX() + 26);
		}
	}
	printf(ANSI_COLOR_MAGENTA);
	//Door control
	for (i = 0;i < doors.size();i++) {
		if (doors[i].getOpen()) {
			doors[i].setTime();
			if (doors[i].getTime() == 0 && terrain[doors[i].getX()][doors[i].getY()] == 'D') {
				printf("\x1b[%d;%dHD", doors[i].getX() + 7, doors[i].getY() + 26);
				doors[i].setOpen(false);
			}
			else if (terrain[doors[i].getX()][doors[i].getY()] == 'D') {
				printf("\x1b[%d;%dH_", doors[i].getX() + 7, doors[i].getY() + 26);
			}
		}
	}
	printf(ANSI_COLOR_RESET);
}
void Map::printMapFull(Player player) {
	unsigned i;
	unsigned y;

	terrain[player.getY()][player.getX()] = player.getLetter();

	for (i = 0;i < MAPSIZE;i++) {
		printf("\x1b[%d;26H", i + 7);
		for (y = 0;y < MAPSIZE;y++) {
			if (i == players[0].getY() && y == players[0].getX()) printf(ANSI_COLOR_BOLDYELLOW "%c" ANSI_COLOR_RESET, players[0].getLetter());
			else if (i == players[1].getY() && y == players[1].getX()) printf(ANSI_COLOR_BOLDGREEN "%c" ANSI_COLOR_RESET, players[1].getLetter());
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
				player.setMoves(player.getMoves() + 1);
				break;
			case 1:
				player.setMoves(player.getMoves() + 2);
				break;
			case 2:
				player.setMoves(player.getMoves() + 3);
				break;
			case 3:
				player.setMaxMoves(player.getMaxMoves() + 1);
				break;
			case 4:
				player.setDamage(player.getDamage() + 1);
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
void Map::playerHit(unsigned player, Bullet bullet) {
	Player temp_player = players[0];
	
	switch (player)
	{
	case 0:
		temp_player = players[0];
		break;
	default:
		temp_player = players[1];
		break;
	}

	temp_player.setHealt(temp_player.getHealt() - bullet.getDamage());
	temp_player.setStatsChanged(true);
	modifyPlayer(player, temp_player);
}
bool Map::processBullet(unsigned i, Bullet bullet) {
	if (bullet.getPlayer() != 0 && players[0].getY() == bullet.getY() && players[0].getX() == bullet.getX()) {
		playerHit(true, bullet);
		return true;
	}
	else if (bullet.getPlayer() != 1 && players[1].getY() == bullet.getY() && players[1].getX() == bullet.getX()) {
		playerHit(false, bullet);
		return true;
	}
	if (terrain[bullet.getY()][bullet.getX()] == ' ') printf("\x1b[%d;%dH ", bullet.getY() + 7, bullet.getX() + 26);
	switch (bullet.getDir()) {
	case DIR_UP:
		if (terrain[bullet.getY() - 1][bullet.getX()] == ' ') {
			bullet.setY(bullet.getY() - 1);
			modifyBullet(i, bullet);
		}
		else if (bullet.getY() - 1 == players[0].getY() && bullet.getX() == players[0].getX()) {
			playerHit(true, bullet);
			return true;
		}
		else if (bullet.getY() - 1 == players[1].getY() && bullet.getX() == players[1].getX()) {
			playerHit(false, bullet);
			return true;
		}
		else return true;
		break;
	case DIR_DOWN:
		if (terrain[bullet.getY() + 1][bullet.getX()] == ' ') {
			bullet.setY(bullet.getY() + 1);
			modifyBullet(i, bullet);
		}
		else if (bullet.getY() + 1 == players[0].getY() && bullet.getX() == players[0].getX()) {
			playerHit(true, bullet);
			return true;
		}
		else if (bullet.getY() + 1 == players[1].getY() && bullet.getX() == players[1].getX()) {
			playerHit(false, bullet);
			return true;
		}
		else return true;
		break;
	case DIR_RIGHT:
		if (terrain[bullet.getY()][bullet.getX() + 1] == ' ') {
			bullet.setX(bullet.getX() + 1);
			modifyBullet(i, bullet);
		}
		else if (bullet.getY() == players[0].getY() && bullet.getX() + 1 == players[0].getX()) {
			playerHit(true, bullet);
			return true;
		}
		else if (bullet.getY() == players[1].getY() && bullet.getX() + 1 == players[1].getX()) {
			playerHit(false, bullet);;
			return true;
		}
		else return true;
		break;
	case DIR_LEFT:
		if (terrain[bullet.getY()][bullet.getX() - 1] == ' ') {
			bullet.setX(bullet.getX() - 1);
			modifyBullet(i, bullet);
		}
		else if (bullet.getY() == players[0].getY() && bullet.getX() - 1 == players[0].getX()) {
			playerHit(true, bullet);
			return true;
		}
		else if (bullet.getY() == players[1].getY() && bullet.getX() - 1 == players[1].getX()) {
			playerHit(false, bullet);
			return true;
		}
		else return true;
		break;
	default:
		return true;
	}
	return false;
}
