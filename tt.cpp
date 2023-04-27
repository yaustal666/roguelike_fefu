#include <iostream>
#include <random>

#include "Spawner.cpp"

int main() {
  Spawner sp(20, 20, 5, 'Z', 3);

  Enemy* en = sp.spawn();
}