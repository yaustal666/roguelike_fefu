#include "Map.hpp"

#include <iostream>
void Map::buildHeightsMap() {
  heights_map_.clear();

  for (int i = 0; i < map_y_size; ++i) {
    std::vector<bool> heights_line;

    for (int j = 0; j < map_x_size; ++j) {
      bool high;
      high = visual_map_[i][j] == '.';

      heights_line.push_back(high);
    }

    heights_map_.push_back(heights_line);
  }
}

void Map::buildPathfindingMap(short y, short x) {
  pathfinding_map_.clear();
  short curr_y;

  for (int i = 0; i < map_y_size; ++i) {
    std::vector<short> tmp;

    if (i <= y)
      curr_y = y - i;
    else
      curr_y = -(y - i);

    short curr_x;

    for (int j = 0; j < map_x_size; ++j) {
      if (j <= x)
        curr_x = x - j;
      else
        curr_x = -(x - j);

      tmp.push_back(curr_x + curr_y);
    }
    pathfinding_map_.push_back(tmp);
  }

  for (int i = 0; i < map_y_size; ++i) {
    for (int j = 0; j < map_x_size; ++j) {
      std::cout << pathfinding_map_[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

bool Map::getHsMap(short y, short x) { return heights_map_[y][x]; }
short Map::getPsMap(short y, short x) { return pathfinding_map_[y][x]; }
char Map::getVlMap(short y, short x) { return visual_map_[y][x]; }

// std::vector<std::pair<short, short>> Map::getRadius(short y, short x,
//                                                     short rad) {
//   std::vector<std::pair<short, short>> res;

//   int tmp_ys = y - rad;
//   if (tmp_ys < 1) tmp_ys = 1;
//   int tmp_xs = x - rad;
//   if (tmp_xs < 1) tmp_xs = 1;

//   int tmp_ye = y + rad;
//   if (tmp_ye > 18) tmp_ye = 18;
//   int tmp_xe = x + rad;
//   if (tmp_xe > 98) tmp_xe = 98;

//   for (int i = tmp_ys; i < tmp_ye; ++i)
//     for (int j = tmp_xs; j < tmp_xe; j++) {
//     }
// }