cmake_minimum_required(VERSION 3.22)
project(Minesweepper)

set(CMAKE_CXX_STANDARD 14)

add_executable(Minesweepper Cpp/main.cpp Cpp/Map.cpp Headers/Map.h Cpp/Game.cpp Headers/Game.h Cpp/Keyboard.cpp Headers/Keyboard.h Cpp/Cursor.cpp Headers/Cursor.h Cpp/Moveable.cpp Headers/Moveable.h)
