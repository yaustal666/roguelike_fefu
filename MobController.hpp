#pragma once

#include <functional>
#include <unordered_map>
#include <vector>

#include "Spawner.cpp"

class MobController {
 public:
  std::hash<int> hasher;
  std::unordered_map<int, std::shared_ptr<Enemy>> enemies_;
  std::unordered_map<int, Spawner> spawners_;

  MobController(std::vector<Spawner>);

  void inflictDamage(int, int, char, int);

  void updateEnemies();

  void moveEnemies(std::vector<char>);

  std::vector<std::pair<int, int>> enemiesPos();

  Spawner* getSpawner(int, int);
  Zombie* getZombie(int, int);
  Skeleton* getSkeleton(int, int);
  Golem* getGolem(int, int);

  ~MobController() = default;
};
