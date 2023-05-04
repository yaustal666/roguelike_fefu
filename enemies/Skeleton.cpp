#include "Skeleton.hpp"

Skeleton::Skeleton(short y, short x, short spawner_id) {
  this->setY(y);
  this->setX(x);
  this->setSpawnerID(spawner_id);

  this->setHP(skeleton_hp);
  this->setDMG(skeleton_dmg);
  this->setSYM(skeleton_sym);
}

void Skeleton::move(char direction) {
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