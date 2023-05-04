#pragma once

#include "Enemy.hpp"

class Skeleton : public Enemy {
 public:
  Skeleton(short, short, short);
  void move(char) override;

  ~Skeleton() = default;
};
