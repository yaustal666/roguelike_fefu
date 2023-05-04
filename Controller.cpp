#include "Controller.hpp"

void Controller::initPlayer() {
  player_.setY(player_start_y);
  player_.setX(player_start_x);
  player_.setHP(player_hp);
  player_.setDmg(player_dmg);
  player_.setSYM(player_sym);
}

void Controller::initSpawners(std::ifstream& file) {
  mbc_.createSpawners(file);
}

void Controller::spawnEnemies() { mbc_.spawnEnemies(map_.heights_map_); }

// managing map visual
void Controller::readMap(std::ifstream& file) {
  for (std::string line; getline(file, line);) {
    std::vector<char> tmp;
    for (char i : line) {
      tmp.push_back(i);
    }
    map_.visual_map_.push_back(tmp);
  }
}

void Controller::addSpawnersToMap() {
  for (auto i : mbc_.spawners_) {
    int y = i.second->getY();
    int x = i.second->getX();
    char sym = i.second->getSym();

    map_.visual_map_[y][x] = sym;
  }
}

void Controller::removePlayerFromMap() {
  int y = player_.getY();
  int x = player_.getX();

  map_.visual_map_[y][x] = grass_sym;
}

void Controller::updatePlayerOnMap() {
  int y = player_.getY();
  int x = player_.getX();
  char sym = player_.getSYM();

  map_.visual_map_[y][x] = sym;
}

void Controller::removeEnemiesFromMap() {
  std::vector<std::pair<short, short>> tmp = mbc_.getEnemiesPositions();

  for (auto i : tmp) {
    int y = i.first;
    int x = i.second;

    map_.visual_map_[y][x] = grass_sym;
  }
}

void Controller::updateEnemiesOnMap() {
  std::vector<std::pair<short, short>> coords = mbc_.getEnemiesPositions();
  std::vector<char> symbols = mbc_.getEnemiesSYM();

  for (int i = 0; i < coords.size(); ++i) {
    int y = coords[i].first;
    int x = coords[i].second;
    char sym = symbols[i];

    map_.visual_map_[y][x] = sym;
  }
}
// //

void Controller::updateHeightsMap() { map_.buildHeightsMap(); }

void Controller::updatePathfindingMap() {
  map_.buildPathfindingMap(player_.getY(), player_.getX());
}

void Controller::printMap() {
  for (int i = 0; i < map_.visual_map_.size(); ++i) {
    for (int j = 0; j < map_.visual_map_[i].size(); ++j)
      addch(map_.visual_map_[i][j]);
    addch('\n');
  }
}

void Controller::controllPlayer(int direction) {
  this->removePlayerFromMap();

  bool check_up, check_down, check_left, check_right;
  check_up = map_.getHsMap(player_.getY() - 1, player_.getX());
  check_down = map_.getHsMap(player_.getY() + 1, player_.getX());
  check_left = map_.getHsMap(player_.getY(), player_.getX() - 1);
  check_right = map_.getHsMap(player_.getY(), player_.getX() + 1);

  if (direction == KEY_UP && check_up) player_.move('u');
  if (direction == KEY_DOWN && check_down) player_.move('d');
  if (direction == KEY_LEFT && check_left) player_.move('l');
  if (direction == KEY_RIGHT && check_right) player_.move('r');

  this->updatePlayerOnMap();
}

std::vector<char> Controller::whereEnemiesMove() {
  std::vector<std::pair<short, short>> coords = mbc_.getEnemiesPositions();
  std::vector<char> res;

  for (auto i : coords) {
    std::vector<char> tmp;
    bool check_up, check_down, check_left, check_right;
    check_up = map_.getHsMap(i.first - 1, i.second);
    check_down = map_.getHsMap(i.first + 1, i.second);
    check_left = map_.getHsMap(i.first, i.second - 1);
    check_right = map_.getHsMap(i.first, i.second + 1);

    if (check_up) tmp.push_back('u');
    if (check_down) tmp.push_back('d');
    if (check_left) tmp.push_back('l');
    if (check_right) tmp.push_back('r');

    short a = generate_random(0, tmp.size() - 1);

    res.push_back(tmp[a]);
  }

  return res;
}

void Controller::controlEnemies() {
  this->removeEnemiesFromMap();

  mbc_.moveEnemies(this->whereEnemiesMove());

  this->updateEnemiesOnMap();
}

void Controller::playerGetDamage(short damage) {
  player_.setHP(player_.getHP() - damage);
}
