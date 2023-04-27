#include "Player.hpp"

Player::Player(int x, int y) {
  this->x = x;
  this->y = y;
}

void Player::move_up() { y--; }
void Player::move_down() { y++; }
void Player::move_left() { x--; }
void Player::move_right() { x++; }

void Player::move(char a) {
  switch (a) {
    case 'u': {
      this->move_up();
      break;
    }
    case 'd': {
      this->move_down();
      break;
    }
    case 'l': {
      this->move_left();
      break;
    }
    case 'r': {
      this->move_right();
      break;
    }
  }
}

int Player::getHP() { return hp; }
int Player::getDmg() { return dmg; }
int Player::getX() { return x; }
int Player::getY() { return y; }
char Player::getSYM() { return sym; }

void Player::setHP(int hp) { this->hp = hp; }
void Player::setDmg(int dmg) { this->dmg = dmg; }
void Player::setX(int x) { this->x = x; }
void Player::setY(int y) { this->y = y; }