#pragma once

#include <fstream>
#include <vector>

#include "MobController.cpp"

class Map {
 public:
  std::vector<std::vector<char>> map_;
  std::vector<std::vector<int>> heights_map_;
  std::vector<std::vector<int>> pathfinding_map_;

 public:
  Map() = default;

  Map(std::ifstream&);
  void read(std::ifstream&);

  void buildPMap(int, int);
  void buildHMap();
  void print();

  void parseMobs(MobController&);
  void clearMobs();
  char get(int y, int x);
  char getHMap(int y, int x);
  char getPMap(int y, int x);

  ~Map() = default;
};