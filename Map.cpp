#include "Map.hpp"

Map::Map(std::ifstream &in) { this->read(in); }

void Map::read(std::ifstream &in) {
  for (std::string line; getline(in, line);) {
    std::vector<char> tmp;
    for (char i : line) {
      tmp.push_back(i);
    }
    map_.push_back(tmp);
  }
}

void Map::buildHMap() {
  heights_map_.clear();
  for (auto i : map_) {
    std::vector<int> tmp;
    for (auto j : i) {
      if (j == '.')
        tmp.push_back(1);
      else
        tmp.push_back(0);
    }
    heights_map_.push_back(tmp);
  }
}

void Map::parseMobs(MobController &mbc) {
  for (auto i : mbc.spawners_) {
    int y = i.second.y;
    int x = i.second.x;
    char sym = i.second.sym;

    map_[y][x] = sym;
  }

  for (auto i : mbc.enemies_) {
    int y = i.second->getY();
    int x = i.second->getX();
    char sym = i.second->getSYM();

    map_[y][x] = sym;
  }
}

void Map::clearMobs() {
  for (int i = 0; i < map_.size(); ++i) {
    for (int j = 0; j < map_[i].size(); ++j) {
      if (map_[i][j] != '.' && map_[i][j] != '#') map_[i][j] = '.';
    }
  }
}

char Map::get(int y, int x) { return map_[y][x]; }
char Map::getHMap(int y, int x) { return heights_map_[y][x]; }
char Map::getPMap(int y, int x) { return pathfinding_map_[y][x]; }

void Map::print() {
  for (int i = 0; i < map_.size(); ++i) {
    for (int j = 0; j < map_[i].size(); ++j) addch(map_[i][j]);
    addch('\n');
  }
}
