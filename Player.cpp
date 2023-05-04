#include "Player.hpp"

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