#include "Zombie.hpp"

Zombie::Zombie(short y, short x, short spawner_id) {
  this->setY(y);
  this->setX(x);
  this->setSpawnerID(spawner_id);

  this->setHP(zombie_hp);
  this->setDMG(zombie_dmg);
  this->setSYM(zombie_sym);
}

void Zombie::move(char direction) {
  switch (direction) {
    case 'u': {
      this->move_up();
      break;
    }
    case 'd': {
      this->move_down();
      break;
    }
    case 'l': {
      this->move_left();
      break;
    }
    case 'r': {
      this->move_right();
      break;
    }
  }
}