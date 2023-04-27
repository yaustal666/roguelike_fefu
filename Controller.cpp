#include "Controller.hpp"

Controller::Controller(int x, int y, std::ifstream& file,
                       std::vector<Spawner> vc)
    : player(x, y), mp(file), mbc(vc) {}

void Controller::updateMap() {
  mp.clearMobs();
  mp.parseMobs(mbc);
  mp.buildHMap();
  mp.print();
}

void Controller::listen(int c) {
  int check_up, check_down, check_left, check_right;
  check_up = mp.getHMap(player.getY() - 1, player.getX());
  check_down = mp.getHMap(player.getY() + 1, player.getX());
  check_left = mp.getHMap(player.getY(), player.getX() - 1);
  check_right = mp.getHMap(player.getY(), player.getX() + 1);

  if (c == KEY_UP && check_up) player.move('u');
  if (c == KEY_DOWN && check_down) player.move('d');
  if (c == KEY_LEFT && check_left) player.move('l');
  if (c == KEY_RIGHT && check_right) player.move('r');
}

void Controller::playerMeleeAttack() {
  char where = getch();
  char who_there = 'n';
  int y, x;

  switch (where) {
    case KEY_UP: {
      y = player.getY() - 1;
      x = player.getX();
      who_there = mp.get(y, x);
      break;
    }
    case KEY_DOWN: {
      y = player.getY() + 1;
      x = player.getX();
      who_there = mp.get(y, x);
      break;
    }
    case KEY_LEFT: {
      y = player.getY();
      x = player.getX() - 1;
      who_there = mp.get(y, x);
      break;
    }
    case KEY_RIGHT: {
      y = player.getY();
      x = player.getX() + 1;
      who_there = mp.get(player.getY(), player.getX() + 1);
      break;
    }

      if (who_there != 'n') {
        mbc.inflictDamage(y, x, who_there, 4);
      }
  }
}

void Controller::printPlayer() {
  mvaddch(player.getY(), player.getX(), player.getSYM());
}

int Controller::getPlayerX() { return player.getX(); }
int Controller::getPlayerY() { return player.getY(); }
char Controller::getPlayerSYM() { return player.getSYM(); }

Spawner* Controller::getSpawner(int y, int x) { return mbc.getSpawner(y, x); }