#pragma once

#include <ncurses.h>

#include "Map.cpp"
#include "Player.cpp"
#include "enemies/MobController.cpp"

class Controller {
 private:
  Map map_;
  MobController mbc_;
  Player player_;

 public:
  Controller() = default;

  void initPlayer();
  void initSpawners(std::ifstream&);

  void readMap(std::ifstream&);
  void addSpawnersToMap();
  void removeEnemiesFromMap();
  void updateEnemiesOnMap();
  void removePlayerFromMap();
  void updatePlayerOnMap();

  void spawnEnemies();

  void updateHeightsMap();
  void updatePathfindingMap(short, short);

  void printMap();

  void controllPlayer(int);

  std::vector<char> whereEnemiesMove();
  void controlEnemies();

  ~Controller() = default;
};
