#include "Skeleton.hpp"

void Skeleton::getDamage(int dmg) { hp -= dmg; }

Skeleton::Skeleton(int y, int x, char sym) {
  this->x = x;
  this->y = y;
  this->sym = sym;
}