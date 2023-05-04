#pragma once

#include <fstream>
#include <functional>
#include <memory>
#include <unordered_map>
#include <vector>

#include "Spawner.cpp"

class MobController {
 public:
  std::hash<int> hasher_;
  std::unordered_map<short, std::shared_ptr<Enemy>> enemies_;
  std::unordered_map<short, std::shared_ptr<Spawner>> spawners_;

  MobController() = default;

  void createSpawners(std::ifstream&);

  void spawnEnemies(const std::vector<std::vector<bool>>&);

  void moveEnemies(std::vector<char>);

  std::vector<std::pair<short, short>> getEnemiesPositions();
  std::vector<char> getEnemiesSYM();

  ~MobController() = default;
};
