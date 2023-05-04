#include "Golem.hpp"

Golem::Golem(short y, short x, short spawner_id) {
  this->setY(y);
  this->setX(x);
  this->setSpawnerID(spawner_id);

  this->setHP(golem_hp);
  this->setDMG(golem_dmg);
  this->setSYM(golem_sym);
}

void Golem::move(char direction) {
  if (timer % 3 != 0) return;

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