#pragma once
#include <ncurses.h>

#include "Map.cpp"
#include "Player.cpp"

class Controller {
 public:
  Player player;
  Map mp;
  MobController mbc;

  Controller(int, int, std::ifstream&, std::vector<Spawner>);

  int getPlayerX();
  int getPlayerY();
  char getPlayerSYM();

  void listen(int);

  void updateMap();

  void playerMeleeAttack();

  std::vector<char> whereEnemiesMove(std::vector<std::pair<int, int>>);

  char findRandomFreePlace(int, int);

  Spawner* getSpawner(int, int);

  void printPlayer();
  ~Controller() = default;
};
