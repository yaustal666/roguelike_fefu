#include "Spawner.hpp"

Spawner::Spawner(int y, int x, int range, char sym, int capacity) {
  this->y = y;
  this->x = x;
  this->range = range;
  this->sym = sym;
  this->capacity = capacity;
}

std::shared_ptr<Enemy> Spawner::spawn() {
  int y = rand_num(this->y - range, this->y + range);
  if (y <= 1) y = 1;
  if (y >= 19) y = 18;

  int x = rand_num(this->x - range, this->x + range);

  if (x <= 1) x = 1;
  if (x >= 99) x = 98;

  std::shared_ptr<Enemy> enem;
  if (sym == 'Z') enem = std::make_shared<Zombie>(y, x, 'z');
  if (sym == 'S') enem = std::make_shared<Skeleton>(y, x, 's');
  if (sym == 'G') enem = std::make_shared<Golem>(y, x, 'g');

  return enem;
}