#include "Spawner.hpp"

#include <iostream>
Spawner::Spawner(short y, short x, int id, short capacity, char sym) {
  this->y = y;
  this->x = x;
  this->id = id;
  this->capacity_ = capacity;
  this->sym = sym;
}

std::shared_ptr<Enemy> Spawner::spawn(
    const std::vector<std::vector<bool>>& hm) {
  if (current_ >= capacity_) return nullptr;

  short range = get_range(sym);
  short tmpy = y;
  short tmpx = x;

  while (!hm[tmpy][tmpx]) {
    tmpy = generate_random(y - range, y + range);
    tmpx = generate_random(x - range, x + range);

    // std::cout << tmpy << " " << tmpx << std::endl;

    if (tmpy < 1) tmpy = 1;
    if (tmpx < 1) tmpx = 1;
    if (tmpy > 18) tmpy = 18;
    if (tmpx > 98) tmpx = 98;
  }

  // std::cout << std::endl;

  std::shared_ptr<Enemy> enem;
  if (sym == zombie_spawner_sym)
    enem = std::make_shared<Zombie>(tmpy, tmpx, zombie_sym);

  if (sym == skeleton_spawner_sym)
    enem = std::make_shared<Skeleton>(tmpy, tmpx, skeleton_sym);

  if (sym == golem_spawner_sym)
    enem = std::make_shared<Golem>(tmpy, tmpx, golem_sym);

  current_++;

  return enem;
}