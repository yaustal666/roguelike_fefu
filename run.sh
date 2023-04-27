#! /usr/bin/bash

clang++ -fsanitize=address  -fsanitize=undefined -std=c++20 game.cpp -lncurses
./a.out