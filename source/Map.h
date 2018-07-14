#ifndef _Map_H_
#define _Map_H_

#include <vector>
#include <random>
#include "time.h"
#include "Player.h"
#include "Door.h"
#include "Input.h"
#include "Object.h"

const unsigned MAPSIZE = 32;

class Map{
  private:
    char terrain[MAPSIZE][MAPSIZE];
    std::vector<Player> players;
    std::vector<Door> doors;
    std::vector<Bullet> bullets;
    std::vector<Object> objects;
    int getDoorPosition(unsigned x, unsigned y) const;
    bool processBullet(unsigned i, Bullet bullet);
    void playerHit(bool player_1, Bullet bullet);
  public:
    Map();
    void printMapFull(Player player);
    void printMapOptimized(Player player, bool player_1);
    Player getPlayer(bool player_1) const;
    Object getObject(unsigned i) const { return objects[i]; };
    void modifyPlayer(bool player_1, Player player);
    void modifyBullet(unsigned position, Bullet bullet);
    bool processMovement(Player &player, Dir dir);
    bool processGame(Player &player, bool player_1, int &special, int &inventory_index, u64 kDown);
};

#endif
