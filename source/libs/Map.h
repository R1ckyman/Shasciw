#ifndef _Map_H_
#define _Map_H_

#include <random>
#include "time.h"
#include "Player.h"
#include "Door.h"
#include "Input.h"
#include "Object.h"

const unsigned MAPSIZE = 32;

class Map {
private:
	unsigned playerCount;
	char terrain[MAPSIZE][MAPSIZE];
	std::vector<Player> players;
	std::vector<Door> doors;
	std::vector<Bullet> bullets;
	std::vector<Object> objects;
	int getDoorPosition(unsigned x, unsigned y) const;
	int getObjectPosition(unsigned x, unsigned y) const;
	bool processBullet(unsigned i, Bullet bullet);
	void playerHit(unsigned player, const Bullet &bullet);
	bool bulletHit(const Bullet &bullet, Dir dir);
public:
	Map();
	void printMapFull(Player player);
	void printMapOptimized(Player player);
	unsigned getPlayers() const { return playerCount; };
	Player getPlayer(unsigned player) const;
	Object getObject(unsigned i) const { return objects[i]; };
	void modifyPlayer(unsigned player_index, Player player);
	void modifyBullet(unsigned position, Bullet bullet);
	bool processMovement(Player &player, Dir dir);
	bool processGame(Player &player, int &special, unsigned &inventory_index, u64 kDown);
};

#endif
