#include <random>

const int max_zombies = 3;
const int max_sceletons = 2;
const int max_golems = 1;

int get_max_enemy(char sym) {
  int res;
  switch (sym) {
    case 'Z':
      res = max_zombies;
      break;
    case 'S':
      res = max_sceletons;
      break;
    case 'G':
      res = max_golems;
      break;
  }

  return res;
}

const int zombie_hp = 15;
const int skeleton_hp = 8;
const int golem_hp = 35;

const int zombie_dmg = 2;
const int skeleton_dmg = 3;
const int golem_dmg = 4;

const char zombie_sym = 'z';
const char skeleton_sym = 's';
const char golem_sym = 'g';

int rand_num(int lr, int rr) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distr(lr, rr);

  return distr(gen);
}