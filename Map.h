#ifndef MINESWEEPPER_MAP_H
#define MINESWEEPPER_MAP_H

#include <iostream>
#include <windows.h>
#include <vector>
#include <conio.h>
#include <stack>

using namespace std;

class Map {
private:
    int counterFlags = 0;
    const int EMPTY_CELL = 0;
    const int MINE = 10;
    const int FlAG = 2;
    int size;
    int mines;
    const int BORDER = 100;
    vector<vector<int>> map;
    vector<vector<int>> mask;

public:

    enum GameStatus {
        inProgress,
        Win,
        Lose
    };

    Map();

    int getSize();

    int getMines();

    int setFlag(int x, int y);

    bool checkFlag(int x, int y);

    bool isBorder(int x, int y);

    void initMap();

    int openCell(int x, int y);

    int revealEmptyCell(int px, int py);

    void setMines(int mines);

    void setDigits();

    void show();

    GameStatus check(int x, int y);
};


#endif //MINESWEEPPER_MAP_H
