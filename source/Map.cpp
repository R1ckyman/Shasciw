#include "Map.h"

Map::Map(){
  unsigned i;
  unsigned y;
  char name_1[8] = {'P','l','a','y','e','r','1','\0'};
  char name_2[8] = {'P','l','a','y','e','r','2','\0'};
  Player player_1(name_1,2,12);
  Player player_2(name_2,13,1);
  char map[MAPSIZE][MAPSIZE] = {
  {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
  {'#',' ','o','#','C',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','D',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#'},
  {'#',' ',' ','#',' ',' ',' ',' ','#',' ','#',' ',' ','#',' ','#','#',' ',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#'},
  {'#',' ',' ','#','o','#','D','#','#','D','#','#',' ','#','#','#','#','#','#','#','#','#','#','#','D','#','#','#','#','#','D','#'},
  {'#',' ','#','#','#',' ',' ',' ','M',' ',' ','#',' ','#',' ','D',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
  {'#',' ',' ',' ','D',' ',' ',' ','D',' ',' ','D',' ','#',' ','#','#','#','#','#','#','#','#','#','D','#','#','#','#','#',' ','#'},
  {'#',' ',' ',' ','#','#','D','#','#',' ',' ','#',' ',' ',' ','#','#','#','O',' ',' ','#','#','#',' ','#','#','#','#','#',' ','#'},
  {'#',' ',' ',' ',' ','#',' ','#',' ',' ',' ','#','D','#',' ','#','#','#',' ','#',' ','#','#','#',' ','#','#','o','#','#',' ','#'},
  {'#',' ','#',' ',' ','#',' ',' ',' ','M',' ',' ',' ','#',' ','#','#','#',' ','#',' ',' ',' ','#',' ','#','#',' ','#','#',' ','#'},
  {'#',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ','#','#','#',' ','#',' ','#',' ',' ',' ','D',' ',' ',' ','D',' ','#'},
  {'#',' ','#','#',' ',' ','#','#','#',' ',' ','#','#','#','D','#','#','#','o',' ',' ','#','#','#',' ','#','#',' ','#','#',' ','#'},
  {'#',' ',' ','D',' ',' ',' ',' ',' ',' ',' ','D',' ',' ','o','#','#','#','#','#','#','#','#','#',' ','#','#','O','#','#',' ','#'},
  {'#',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ',' ','#',' ',' ',' ','#','#','#','#','#','D','#','#','#','#','#',' ','#'},
  {'#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ','D',' ',' ',' ','D',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
  {'#',' ',' ','#','o',' ','D',' ',' ',' ',' ','D','O',' ',' ','#',' ',' ',' ','#','#','#','#','#','D','#','#','#','#','#',' ','#'},
  {'#','#','#','#','#','D','#','#','#','#','#','#','#','#','D','#','#','o','#','#','#','#','#','#',' ','#','#','#','#','#',' ','#'},
  {'#','o','#',' ',' ',' ',' ',' ',' ','#','o',' ','#','#',' ','#','#','#','#','#','#','#','#','#',' ','#','#','#','#','o',' ','#'},
  {'#',' ','#','#',' ','#',' ','#','#','#',' ',' ','#','#',' ','#','#','#','#','#','#','#','#','#',' ','#','#','#','#','#',' ','#'},
  {'#',' ',' ','#',' ',' ',' ',' ',' ','D',' ',' ','#','#',' ','#','#','#','#','#','#','#','#','#','D','#','#','#','#','#',' ','#'},
  {'#',' ',' ',' ',' ',' ',' ',' ','#','#','#','D','#','#','D','#','#','#','#','#','#','#',' ',' ',' ',' ',' ','#','#','#',' ','#'},
  {'#','D','#',' ','#','#',' ',' ','D',' ',' ',' ','#',' ',' ',' ','o','#','#','#','#','#',' ','#','#','#',' ','#','#','#',' ','#'},
  {'#',' ','#',' ',' ','#',' ',' ','#',' ',' ',' ','#',' ','#','#',' ','#','#','#','#','#',' ','#','#','#',' ','#','#','#',' ','#'},
  {'#',' ','#',' ','o','#',' ',' ','#','o',' ',' ','D',' ','o','#',' ','D',' ',' ',' ',' ',' ','#','#','#',' ','D',' ','D',' ','#'},
  {'#',' ','#','#','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#','#','#','#',' ','#','#','#',' ','#','#','#',' ','#'},
  {'#',' ',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ','#','#','#',' ','#'},
  {'#','#','#','D','#','#','#','#',' ','#','#','#','#','#','#','D','#','#','#','#','#','#','#','#','D','#','#','#','#','#',' ','#'},
  {'#','#',' ',' ','#','#','#','o',' ',' ','#','#','#','#','#',' ','#','#','#','#','#','#','#','#',' ','#','#','#','#','#',' ','#'},
  {'#','#',' ',' ','#','#','#','#',' ','#','#','#','#','#','#',' ','#','#','#','#','#','#','#','#',' ','#','#','#','#','#',' ','#'},
  {'#','O',' ',' ','#','#','#','#',' ','#','#','#','#','#','#',' ','#','#','#','#','#','#','#','#',' ','#','#','#','#','#',' ','#'},
  {'#',' ',' ',' ','#','#','#','#','D','#','#','#','#','#','#',' ','#','#','#','#','#','#','#','#','D','#','#','#','#','#',' ','#'},
  {'#','#',' ',' ','D',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
  {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}
  };
  for(i=0;i<MAPSIZE;i++){
    for(y=0;y<MAPSIZE;y++){
      terrain[i][y] = map[i][y];
      if(terrain[i][y] == 'D'){
        Door door(i, y);
        doors.push_back(door);
      }
    }
  }
  players.push_back(player_1);
  players.push_back(player_2);
}
void Map::modifyPlayer(unsigned position, Player player){
  players[position] = player;
}
void Map::modifyBullet(unsigned position, Bullet bullet){
  bullets[position] = bullet;
}
int Map::getDoorPosition(unsigned x, unsigned y) const{
  unsigned i;

  for (i = 0; i < doors.size(); i++) {
    if(doors[i].getX() == x && doors[i].getY() == y){
      return i;
    }
  }
  return -1;
}
void Map::printMap(bool player_1){
  unsigned i;
  unsigned y;

  int position;

  terrain[players[0].getY()][players[0].getX()] = players[0].getLetter();
  terrain[players[1].getY()][players[1].getX()] = players[1].getLetter();

  if(player_1) players[0].printStats(11);
  else players[1].printStats(11);

  for(i=0;i<bullets.size();i++){
    if(processBullet(i, bullets[i])){
      terrain[bullets[i].getY()][bullets[i].getX()] = ' ';
      bullets.erase(bullets.begin()+i);
    }
  }

  for(i=0;i<MAPSIZE;i++){
    printf("\x1b[%d;26H",i+7);
		for(y=0;y<MAPSIZE;y++){
      position = getDoorPosition(i, y);
      if(position != -1 && !doors[position].getClosed()){
        if((i == players[0].getY() && y == players[0].getX())) printf("\x1b[33m%c\x1b[0m",players[0].getLetter());
        else if (i == players[1].getY() && y == players[0].getX()) printf("\x1b[32m%c\x1b[0m", players[1].getLetter());
        else printf("_");
        doors[position].setTime();
        if(doors[position].getTime() == 0 && (terrain[i][y] == ' ' || terrain[i][y] == '_')){
          doors[position].setClosed(true);
          terrain[i][y] = 'D';
        }
      }
      else if(i == players[0].getY() && y == players[0].getX()) printf("\x1b[33m%c\x1b[0m", players[0].getLetter());
      else if(i == players[1].getY() && y == players[1].getX()) printf("\x1b[32m%c\x1b[0m", players[1].getLetter());
      else if(terrain[i][y] == '*') printf("\x1b[31m%c\x1b[0m", terrain[i][y]);
      else if(terrain[i][y] == 'O' || terrain[i][y] == 'o') printf("\x1b[35m%c\x1b[0m", terrain[i][y]);
  	  else printf("%c", terrain[i][y]);
		}
		printf("\n");
	}
}
bool Map::processGame(Player &player, bool player_1, int &special, int &index, u32 kDown){
  bool action = false;
  int position;

  if(((kDown & KEY_L) && player_1) || ((kDown & KEY_R) && !player_1)){
    switch(special){
      case 0:
        special = 2;
        break;
      case 1:
        //Use object
        break;
      case 2:
        special = 0;
        break;
      default:
        break;
    }
  }
  if((!action) && (((kDown & KEY_ZL) && player_1) || ((kDown & KEY_ZR) && !player_1))){
    switch (special) {
      case 0:
        special = 1;
        index = 0;
        break;
      case 1:
        special = 0;
        player.printStats(11);
        break;
      case 2:
        special = 1;
        index = 0;
        break;
      default:
        break;
    }
  }
  if((!action) && (((kDown & KEY_DUP) && player_1) || ((kDown & KEY_X) && !player_1))){
    switch (special) {
      case 0:
        if(terrain[player.getY()-1][player.getX()] == ' ' || terrain[player.getY()-1][player.getX()] == '_'){
          terrain[player.getY()][player.getX()] = ' ';
          terrain[player.getY()-1][player.getX()] = player.getLetter();
          player.setY(player.getY()-1);
          action = true;
        }
        break;
      case 1:
        if(index > 0) index--;
        break;
      case 2:
        if(terrain[player.getY()-1][player.getX()] == 'D'){
          terrain[player.getY()-1][player.getX()] = '_';
          position = getDoorPosition(player.getY()-1, player.getX());
          doors[position].setClosed(false);
          action = true;
        }
        else if(terrain[player.getY()-1][player.getX()] == ' '){
          terrain[player.getY()][player.getX()] = '*';
          Bullet temp_bullet(player.getX(), player.getY(), DIR_UP);
          bullets.push_back(temp_bullet);
          action = true;
        }
        break;
      default:
        break;
    }
  }
  if((!action) && (((kDown & KEY_DDOWN) && player_1) || ((kDown & KEY_B) && !player_1))){
    switch (special) {
      case 0:
        if(terrain[player.getY()+1][player.getX()] == ' ' || terrain[player.getY()+1][player.getX()] == '_'){
          terrain[player.getY()][player.getX()] = ' ';
          terrain[player.getY()+1][player.getX()] = player.getLetter();
          player.setY(player.getY()+1);
          action = true;
        }
        break;
      case 1:
        if(index < 10) index++;
        break;
      case 2:
        if(terrain[player.getY()+1][player.getX()] == 'D'){
          terrain[player.getY()+1][player.getX()] = '_';
          position = getDoorPosition(player.getY()+1, player.getX());
          doors[position].setClosed(false);
          action = true;
        }
        else if(terrain[player.getY()+1][player.getX()] == ' '){
          terrain[player.getY()][player.getX()] = '*';
          Bullet temp_bullet(player.getX(),player.getY(), DIR_DOWN);
          bullets.push_back(temp_bullet);
          action = true;
        }
        break;
      default:
        break;
    }
  }
  if((!action) && (((kDown & KEY_DLEFT) && player_1) || ((kDown & KEY_Y) && !player_1))){
    switch (special) {
      case 0:
        if(terrain[player.getY()][player.getX()-1] == ' ' || terrain[player.getY()][player.getX()-1] == '_' ){
          terrain[player.getY()][player.getX()] = ' ';
          terrain[player.getY()][player.getX()-1] = player.getLetter();
          player.setX(player.getX()-1);
          action = true;
        }
        break;
      case 1:
        break;
      case 2:
        if(terrain[player.getY()][player.getX()-1] == 'D'){
          terrain[player.getY()][player.getX()-1] = '_';
          position = getDoorPosition(player.getY(), player.getX()-1);
          doors[position].setClosed(false);
          action = true;
        }
        else if(terrain[player.getY()][player.getX()-1] == ' '){
          terrain[player.getY()][player.getX()] = '*';
          Bullet temp_bullet(player.getX(), player.getY(), DIR_LEFT);
          bullets.push_back(temp_bullet);
          action = true;
        }
        break;
      default:
        break;
    }
  }
  if((!action) && (((kDown & KEY_DRIGHT) && player_1) || ((kDown & KEY_A) && !player_1))){
    switch (special) {
      case 0:
        if(terrain[player.getY()][player.getX()+1] == ' ' || terrain[player.getY()][player.getX()+1] == '_'){
          terrain[player.getY()][player.getX()] = ' ';
          terrain[player.getY()][player.getX()+1] = player.getLetter();
          player.setX(player.getX()+1);
          action = true;
        }
        break;
      case 2:
        if(terrain[player.getY()][player.getX()+1] == 'D'){
          terrain[player.getY()][player.getX()+1] = '_';
          position = getDoorPosition(player.getY(), player.getX()+1);
          doors[position].setClosed(false);
          action = true;
        }
        else if(terrain[player.getY()][player.getX()+1] == ' '){
          terrain[player.getY()][player.getX()] = '*';
          Bullet temp_bullet(player.getX(), player.getY(), DIR_RIGHT);
          bullets.push_back(temp_bullet);
          action = true;
        }
        break;
      default:
        break;
    }
  }
  if(special == 1) player.printStats(index);
  if(action) special = 0;
  return action;
}
bool Map::processBullet(unsigned i,Bullet bullet){
  switch (bullet.getDir()) {
    case DIR_UP:
      if(terrain[bullet.getY()-1][bullet.getX()] == ' '){
        terrain[bullet.getY()-1][bullet.getX()] = '*';
        terrain[bullet.getY()][bullet.getX()] = ' ';
        bullet.setY(bullet.getY()-1);
        modifyBullet(i, bullet);
      }
      else if(bullet.getY()-1 == players[0].getY() && bullet.getX() == players[0].getX()){
        Player temp_player = players[0];
        temp_player.setHealt(temp_player.getHealt()-1);
        modifyPlayer(0, temp_player);
        return true;
      }
      else if(bullet.getY()-1 == players[1].getY() && bullet.getX() == players[1].getX()){
        Player temp_player = players[1];
        temp_player.setHealt(temp_player.getHealt()-1);
        modifyPlayer(1, temp_player);
        return true;
      }
      else return true;
      break;
    case DIR_DOWN:
      if(terrain[bullet.getY()+1][bullet.getX()] == ' '){
        terrain[bullet.getY()+1][bullet.getX()] = '*';
        terrain[bullet.getY()][bullet.getX()] = ' ';
        bullet.setY(bullet.getY()+1);
        modifyBullet(i, bullet);
      }
      else if(bullet.getY()+1 == players[0].getY() && bullet.getX() == players[0].getX()){
        Player temp_player = players[0];
        temp_player.setHealt(temp_player.getHealt()-1);
        modifyPlayer(0, temp_player);
        return true;
      }
      else if(bullet.getY()+1 == players[1].getY() && bullet.getX() == players[1].getX()){
        Player temp_player = players[1];
        temp_player.setHealt(temp_player.getHealt()-1);
        modifyPlayer(1, temp_player);
        return true;
      }
      else return true;
      break;
    case DIR_RIGHT:
      if(terrain[bullet.getY()][bullet.getX()+1] == ' '){
        terrain[bullet.getY()][bullet.getX()+1] = '*';
        terrain[bullet.getY()][bullet.getX()] = ' ';
        bullet.setX(bullet.getX()+1);
        modifyBullet(i, bullet);
      }
      else if(bullet.getY() == players[0].getY() && bullet.getX()+1 == players[0].getX()){
        Player temp_player = players[0];
        temp_player.setHealt(temp_player.getHealt()-1);
        modifyPlayer(0, temp_player);
        return true;
      }
      else if(bullet.getY() == players[1].getY() && bullet.getX()+1 == players[1].getX()){
        Player temp_player = players[1];
        temp_player.setHealt(temp_player.getHealt()-1);
        modifyPlayer(1, temp_player);
        return true;
      }
      else return true;
      break;
    case DIR_LEFT:
      if(terrain[bullet.getY()][bullet.getX()-1] == ' '){
        terrain[bullet.getY()][bullet.getX()-1] = '*';
        terrain[bullet.getY()][bullet.getX()] = ' ';
        bullet.setX(bullet.getX()-1);
        modifyBullet(i, bullet);
      }
      else if(bullet.getY() == players[0].getY() && bullet.getX()-1 == players[0].getX()){
        Player temp_player = players[0];
        temp_player.setHealt(temp_player.getHealt()-1);
        modifyPlayer(0, temp_player);
        return true;
      }
      else if(bullet.getY() == players[1].getY() && bullet.getX()-1 == players[1].getX()){
        Player temp_player = players[1];
        temp_player.setHealt(temp_player.getHealt()-1);
        modifyPlayer(1, temp_player);
        return true;
      }
      else return true;
      break;
    default:
      return true;
  }
  return false;
}
