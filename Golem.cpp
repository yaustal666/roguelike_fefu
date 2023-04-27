#include "Golem.hpp"

void Golem::getDamage(int dmg) { hp -= dmg; }

Golem::Golem(int y, int x, char sym) {
  this->x = x;
  this->y = y;
  this->sym = sym;
}