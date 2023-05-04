#pragma once

#include "../Config.hpp"

class Enemy {
 private:
  short x, y;
  short hp;
  short dmg;
  char sym;
  short spawner_id;

 public:
  Enemy() = default;

  void move_up() { y--; };
  void move_down() { y++; };
  void move_left() { x--; };
  void move_right() { x++; };

  void setDMG(short dmg) { this->dmg = dmg; }
  void setHP(short hp) { this->hp = hp; }
  void setX(short x) { this->x = x; }
  void setY(short y) { this->y = y; }
  void setSpawnerID(short spawner_id) { this->spawner_id = spawner_id; }
  void setSYM(char sym) { this->sym = sym; }

  short getDMG() { return dmg; }
  short getHP() { return hp; }
  short getX() { return x; }
  short getY() { return y; }
  short getSpawnerID() { return spawner_id; }
  char getSYM() { return sym; }

  virtual void move(char) = 0;

  ~Enemy() = default;
};