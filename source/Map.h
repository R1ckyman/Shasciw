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
        void printMap(Player player_1, Player player_2);
        Player getPlayer(int i) const { return players[i]; };
        bool gameProcess(Player player, bool player_1);
};

#endif
