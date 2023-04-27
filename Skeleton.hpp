#pragma once

#include "Enemy.hpp"

class Skeleton : public Enemy {
 public:
  Skeleton() = default;
  Skeleton(int, int, char);

  void move(char) override;

  void getDamage(int) override;

  void attack();
  void findPlayer();
  void follow();

  ~Skeleton() = default;
};