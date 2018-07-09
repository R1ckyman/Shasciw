#ifndef _Map_H_
#define _Map_H_

#include <vector>
#include "Player.h"
#include "Door.h"
#include "Bullet.h"
#include "Input.h"

const unsigned MAPSIZE = 32;

class Map{
    private:
        char terrain[MAPSIZE][MAPSIZE];
        std::vector<Player> players;
        std::vector<Door> doors;
        std::vector<Bullet> bullets;
        int getDoorPosition(unsigned x, unsigned y) const;
        bool processBullet(unsigned position, Bullet bullet);
    public:
        Map();
        void printMap(bool player_1);
        Player getPlayer(unsigned position) const { return players[position]; };
        void modifyPlayer(unsigned position, Player player);
        void modifyBullet(unsigned position, Bullet bullet);
        bool processGame(Player &player, bool player_1, int &special, int &inventory_index, u32 kDown);
};

#endif
