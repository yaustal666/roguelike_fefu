#include <ncurses.h>

#include <fstream>
#include <iostream>

#include "Controller.cpp"

int main() {
  // --------Parse spawners Initialize MobController
  int input = 0;
  std::ifstream file("map.txt");
  std::ifstream spawners("spawners.txt");

  std::vector<Spawner> vc;
  int count;
  spawners >> count;

  for (int i = 0; i < count; ++i) {
    int y, x, range;
    char sym;
    spawners >> y >> x >> range >> sym;

    Spawner tmp(y, x, range, sym, get_max_enemy(sym));
    vc.push_back(tmp);
  }

  Controller control(10, 13, file, vc);
  control.mbc.updateEnemies();
  // - start ------------------
  initscr();
  keypad(stdscr, 1);

  do {
    clear();

    control.updateMap();

    control.listen(input);
    control.printPlayer();

  } while ((input = getch()) != 27);

  endwin();
}