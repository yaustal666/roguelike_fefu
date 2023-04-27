#pragma once

#include "Enemy.hpp"

class Golem : public Enemy {
 public:
  Golem() = default;
  Golem(int, int, char);

  void move(char) override;

  void getDamage(int) override;

  void attack();
  void findPlayer();
  void follow();

  ~Golem() = default;
};