#pragma once
#include <cstdlib>

int timer = 0;

short map_y_size = 20;
short map_x_size = 100;

char grass_sym = '.';
char wall_sym = '#';

short player_start_y = 13;
short player_start_x = 20;
short player_hp = 15;
short player_dmg = 2;
char player_sym = '@';

short zombie_hp = 5;
short skeleton_hp = 3;
short golem_hp = 12;

short zombie_dmg = 2;
short skeleton_dmg = 3;
short golem_dmg = 6;

char zombie_sym = 'z';
char skeleton_sym = 's';
char golem_sym = 'g';

enum { zomb = 1, skel, golem };

char zombie_spawner_sym = 'Z';
char skeleton_spawner_sym = 'S';
char golem_spawner_sym = 'G';

char get_spawner_sym(short type) {
  if (type == zomb) return zombie_spawner_sym;
  if (type == skel) return skeleton_spawner_sym;
  return golem_spawner_sym;
}

short zomb_spawner_capacity = 3;
short skel_spawner_capacity = 2;
short golem_spawner_capacity = 1;

short get_capacity(short type) {
  if (type == zomb) return zomb_spawner_capacity;
  if (type == skel) return skel_spawner_capacity;
  return golem_spawner_capacity;
}

short zombie_spawner_range = 10;
short skeleton_spawner_range = 10;
short golem_spawner_range = 3;

short get_range(char type) {
  if (type == 'Z') return zombie_spawner_range;
  if (type == 'S') return skeleton_spawner_range;
  return golem_spawner_range;
}

short generate_random(short left, short right) {
  return left + (rand() % (right - left + 1));
}

void tick() { timer++; }