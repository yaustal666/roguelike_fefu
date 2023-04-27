#pragma once

class Enemy {
 private:
 public:
  int hp;
  int dmg;
  int x, y;
  int spawner_id;
  char sym;

 public:
  Enemy() = default;

  void seDMG(int dmg) { this->dmg = dmg; }
  void setX(int x) { this->x = x; }
  void setY(int y) { this->y = y; }
  void setSpawnerID(int spawner_id) { this->spawner_id = spawner_id; }

  int geDMG() { return dmg; }
  int getX() { return x; }
  int getY() { return y; }
  int getSpawnerID() { return spawner_id; }
  char getSYM() { return sym; }

  virtual void getDamage(int) = 0;

  virtual void move(char) = 0;

  virtual ~Enemy() = default;
};
