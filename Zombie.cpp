#include "Zombie.hpp"

Zombie::Zombie(int y, int x, char sym) {
  this->x = x;
  this->y = y;
  this->sym = sym;
}
void Zombie::getDamage(int dmg) { hp -= dmg; }