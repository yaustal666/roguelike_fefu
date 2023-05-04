#pragma once

#include <memory>

#include "Golem.cpp"
#include "Skeleton.cpp"
#include "Zombie.cpp"

class Spawner {
 private:
  short x, y;
  int id;
  short capacity_;
  short current_ = 0;
  short timer;
  char sym;

 public:
  Spawner(short, short, int, short, char);

  short getX() { return x; }
  short getY() { return y; }
  char getSym() { return sym; }

  std::shared_ptr<Enemy> spawn(const std::vector<std::vector<bool>>&);

  ~Spawner() = default;
};
