#pragma once

class Player {
 private:
  int hp = 20;
  int dmg = 4;
  int x, y;
  char sym = '@';

 public:
  Player() = default;
  Player(int, int);

  void move(char);

  void move_up();
  void move_down();
  void move_left();
  void move_right();

  int getHP();
  int getDmg();
  int getX();
  int getY();
  char getSYM();

  void setHP(int);
  void setDmg(int);
  void setX(int);
  void setY(int);

  ~Player() = default;
};