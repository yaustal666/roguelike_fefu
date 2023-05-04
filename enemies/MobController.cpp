#include "MobController.hpp"

#include <iostream>
void MobController::createSpawners(std::ifstream& file) {
  int count;
  file >> count;

  for (int i = 0; i < count; ++i) {
    short y, x, type;

    file >> y >> x >> type;

    int id = hasher_(y + x);

    std::shared_ptr<Spawner> spawner;

    spawner = std::make_shared<Spawner>(y, x, id, get_capacity(type),
                                        get_spawner_sym(type));

    spawners_.insert({id, spawner});
  }
}

void MobController::spawnEnemies(const std::vector<std::vector<bool>>& hm) {
  for (auto i : spawners_) {
    std::shared_ptr<Enemy> ptr = nullptr;
    ptr = i.second->spawn(hm);

    if (ptr != nullptr) {
      int h = hasher_(ptr->getX() + ptr->getY());

      // std::cout << ptr->getX() << " " << ptr->getY() << std::endl;
      enemies_.insert({h, ptr});
    }
  }
}

void MobController::moveEnemies(std::vector<char> directions) {
  int count = 0;
  for (auto i : enemies_) {
    i.second->move(directions[count]);
    count++;
  }
}

std::vector<std::pair<short, short>> MobController::getEnemiesPositions() {
  std::vector<std::pair<short, short>> res;

  for (auto i : enemies_) {
    int y = i.second->getY();
    int x = i.second->getX();

    std::pair<short, short> tmp = std::make_pair(y, x);

    res.push_back(tmp);
  }

  return res;
}

std::vector<char> MobController::getEnemiesSYM() {
  std::vector<char> res;

  for (auto i : enemies_) {
    char sym = i.second->getSYM();

    res.push_back(sym);
  }

  return res;
}