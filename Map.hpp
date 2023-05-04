#pragma once

#include <vector>

#include "Config.hpp"

class Map {
 public:
  std::vector<std::vector<char>> visual_map_;
  std::vector<std::vector<bool>> heights_map_;
  std::vector<std::vector<short>> pathfinding_map_;

  Map() = default;

  void buildHeightsMap();

  bool getHsMap(int, int);
  short getPsMap(int, int);
  char getVlMap(int, int);

  std::vector<std::pair<short, short>> getRadius(short, short, short);

  ~Map() = default;
};
