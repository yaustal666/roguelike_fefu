#include <ncurses.h>

#include "Controller.cpp"

int main() {
  int input = 0;
  srand((unsigned)time(NULL));

  std::ifstream map("map.txt");
  std::ifstream spawners("spawners.txt");

  Controller control;

  control.initPlayer();
  control.initSpawners(spawners);
  control.readMap(map);
  control.addSpawnersToMap();
  control.updatePlayerOnMap();
  control.updateHeightsMap();
  control.spawnEnemies();
  control.updateEnemiesOnMap();

  // - start ------------------
  initscr();
  keypad(stdscr, 1);

  do {
    clear();

    if (timer % 10 == 0 && timer) {
      control.spawnEnemies();
      control.updateEnemiesOnMap();
    }

    control.updateHeightsMap();

    control.controllPlayer(input);
    control.controlEnemies();

    control.printMap();

    tick();
  } while ((input = getch()) != 27);

  endwin();
}