#include "Skeleton.hpp"

void Skeleton::getDamage(int dmg) { hp -= dmg; }

Skeleton::Skeleton(int y, int x, char sym) {
  this->x = x;
  this->y = y;
  this->sym = sym;
}

void Skeleton::move(char where) {
  int a = rand_num(1, 4);
  if (a == 1) y--;
  if (a == 2) y++;
  if (a == 3) x--;
  if (a == 4) x++;
}