#pragma once

#include "Enemy.hpp"

class Zombie : public Enemy {
 public:
  Zombie(short, short, short);
  void move(char) override;

  ~Zombie() = default;
};
