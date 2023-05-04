#pragma once

#include "Enemy.hpp"

class Golem : public Enemy {
 public:
  Golem(short, short, short);

  void move(char) override;

  ~Golem() = default;
};
