#pragma once

#include <memory>

#include "Config.cpp"
#include "Golem.cpp"
#include "Skeleton.cpp"
#include "Zombie.cpp"

class Spawner {
 public:
  int x, y;
  int range;
  char sym;
  int capacity;
  int timer;

  Spawner(int, int, int, char, int);

  std::shared_ptr<Enemy> spawn();

  ~Spawner() = default;
};