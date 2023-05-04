#pragma once

class Player {
 private:
  short hp;
  short dmg;
  short x, y;
  char sym;

 public:
  Player() = default;

  void move(char);

  void move_up();
  void move_down();
  void move_left();
  void move_right();

  int getHP() { return hp; }
  int getDmg() { return dmg; }
  int getX() { return x; }
  int getY() { return y; }
  char getSYM() { return sym; }

  void setHP(int hp) { this->hp = hp; }
  void setDmg(int dmg) { this->dmg = dmg; }
  void setX(int x) { this->x = x; }
  void setY(int y) { this->y = y; }
  void setSYM(char sym) { this->sym = sym; };

    ~Player() = default;
};