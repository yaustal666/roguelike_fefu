#include "Zombie.hpp"

Zombie::Zombie(int y, int x, char sym) {
  this->x = x;
  this->y = y;
  this->sym = sym;
}
void Zombie::getDamage(int dmg) { hp -= dmg; }

void Zombie::move(char where) {
  switch (where) {
    case 'u': {
      y--;
      break;
    }
    case 'd': {
      y++;
      break;
    }
    case 'l': {
      x--;
      break;
    }
    case 'r': {
      x++;
      break;
    }
    case '.': {
      break;
    }
  }
}