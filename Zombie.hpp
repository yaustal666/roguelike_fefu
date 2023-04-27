#pragma once

#include "Enemy.hpp"

class Zombie : public Enemy {
 public:
  Zombie() = default;
  Zombie(int, int, char);

  void move();

  void getDamage(int) override;

  void attack();
  void findPlayer();
  void follow();

  ~Zombie() override = default;
};