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

  //   void setPlayer(int, int, int, int);
  //   void setMap(std::ifstream&);

  int getPlayerX();
  int getPlayerY();
  char getPlayerSYM();

  void listen(int);

  void updateMap();

  void playerMeleeAttack();

  Spawner* getSpawner(int, int);

  void printPlayer();
  ~Controller() = default;
};
