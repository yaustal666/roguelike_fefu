#include "MobController.hpp"

MobController::MobController(std::vector<Spawner> vc) {
  for (auto i : vc) {
    int h = hasher(i.y + i.x);
    spawners_.insert({h, i});
  }
}

void MobController::inflictDamage(int y, int x, char who, int dmg) {
  int h = hasher(y + x);
  switch (who) { enemies_.find(h)->second->getDamage(dmg); }
}

Spawner* MobController::getSpawner(int y, int x) {
  int h = hasher(y + x);

  return &(*spawners_.find(h)).second;
}

void MobController::updateEnemies() {
  for (auto i : spawners_) {
    std::shared_ptr<Enemy> ptr = nullptr;
    ptr = i.second.spawn();

    if (ptr != nullptr) {
      std::cout << i.second.x << " " << i.second.y << " ";
      std::cout << std::endl;
      std::cout << ptr->x << " " << ptr->y << " ";
      std::cout << std::endl;
      int h = hasher(ptr->getX() + ptr->getY());
      enemies_.insert({h, ptr});
    }
  }
}

std::vector<std::pair<int, int>> MobController::enemiesPos() {
  std::vector<std::pair<int, int>> vc;

  for (auto i : enemies_) {
    std::pair<int, int> pr;
    pr.first = i.second->getY();
    pr.second = i.second->getX();
    vc.push_back(pr);
  }

  return vc;
}

void MobController::moveEnemies(std::vector<char> vc) {
  int j = 0;
  for (auto i : enemies_) {
    i.second->move(vc[j]);
    j++;
  }
}