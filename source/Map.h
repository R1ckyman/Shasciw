#ifndef _Map_H_
#define _Map_H_

#include <vector>
#include "Player.h"
#include "Input.h"

const unsigned MAPSIZE = 32;

class Map{
    private:
        char terrain[MAPSIZE][MAPSIZE];
        std::vector<Player> players;
    public:
        Map();
        void printMap();
        Player getPlayer(unsigned position) const { return players[position]; };
        void modifyPlayer(unsigned position, Player player);
        bool gameProcess(Player &player, bool player_1);
};

#endif
