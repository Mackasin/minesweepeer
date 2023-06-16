
#include "../Headers/Map.h"
#include "../Headers/Moveable.h"
#include <iostream>
#include <vector>
#include <stack>


Map::Map() {
    size = 10;
    mines = 4;
}

int Map::getSize() {
    return size;
}

int Map::getMines() {
    return mines;
}

bool Map::isBorder(int x, int y) {
    return map[x][y] == BORDER;
}

void Map::initMap() {

    for (int i = 0; i < size; i++) {
        vector<int> temp;
        for (int j = 0; j < size; j++) {
            if ((i == 0 || j == 0) || i == size - 1 || j == size - 1)
                temp.push_back(BORDER);
            else
                temp.push_back(EMPTY_CELL);
        }
        map.push_back(temp);
        mask.push_back(temp);
    }
}

int Map::openCell(int x, int y) {

    mask[x][y] = 1;
    return map[x][y];
}

int Map::revealEmptyCell(int px, int py) {
    stack<int> stk;
    stk.push(px);
    stk.push(py);

    int x = 0, y = 0, d = 0;

    while (true) {
        y = stk.top();
        stk.pop();
        x = stk.top();
        stk.pop();

        if (map[x][y + 1] == EMPTY_CELL && mask[x][y + 1] == 0) {
            stk.push(x);
            stk.push(y + 1);
        }
        mask[x][y + 1] = 1;
        d++;
        if (map[x][y - 1] == EMPTY_CELL && mask[x][y - 1] == 0) {
            stk.push(x);
            stk.push(y - 1);
        }
        mask[x][y - 1] = 1;
        d++;
        if (map[x + 1][y + 1] == EMPTY_CELL && mask[x + 1][y + 1] == 0) {
            stk.push(x + 1);
            stk.push(y + 1);
        }
        mask[x + 1][y + 1] = 1;
        d++;
        if (map[x - 1][y + 1] == EMPTY_CELL && mask[x - 1][y + 1] == 0) {
            stk.push(x - 1);
            stk.push(y + 1);
        }
        mask[x - 1][y + 1] = 1;
        d++;

        if (map[x + 1][y - 1] == EMPTY_CELL && mask[x + 1][y - 1] == 0) {
            stk.push(x + 1);
            stk.push(y - 1);
        }
        mask[x + 1][y - 1] = 1;

        if (map[x - 1][y - 1] == EMPTY_CELL && mask[x - 1][y - 1] == 0) {
            stk.push(x - 1);
            stk.push(y + 1);
        }
        mask[x - 1][y - 1] = 1;
        d++;
        if (map[x + 1][y] == EMPTY_CELL && mask[x + 1][y] == 0) {
            stk.push(x + 1);
            stk.push(y);
        }
        mask[x + 1][y] = 1;
        d++;
        if (map[x - 1][y] == EMPTY_CELL && mask[x - 1][y] == 0) {
            stk.push(x - 1);
            stk.push(y);
        }
        mask[x - 1][y] = 1;
        d++;

        if (stk.empty())
            break;
    }
    show();
    return d;
}

void Map::setMines(int mines) {
    int x;
    int y;
    if (mines >= (size - 2) * (size - 2)) {
        cout << "too many mines\n";
        return;
    }
    while (mines != 0) {
        do {
            x = rand() % (size - 2) + 1;
            y = rand() % (size - 2) + 1;
        } while (map[x][y] == MINE);
        map[x][y] = MINE;

        mines--;
    }
}

void Map::setDigits() {
    int d = 0;
    for (int i = 1; i < size - 1; i++) {

        for (int j = 1; j < size - 1; j++) {
            if (map[j][i] == MINE)
                continue;
            if (map[j][i + 1] == MINE) {
                d++;
            }
            if (map[j][i - 1] == MINE) {
                d++;
            }
            if (map[j + 1][i] == MINE) {
                d++;
            }
            if (map[j - 1][i] == MINE) {
                d++;
            }
            if (map[j + 1][i - 1] == MINE) {
                d++;
            }
            if (map[j + 1][i + 1] == MINE) {
                d++;
            }
            if (map[j - 1][i - 1] == MINE) {
                d++;
            }
            if (map[j - 1][i + 1] == MINE) {
                d++;
            }
            map[j][i] = d;
            d = 0;
        }
    }
}

void Map::show() {
    Moveable::gotoxy(0, 0);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (mask[j][i] == EMPTY_CELL) {
                cout << ".";
                continue;
            }
            if (mask[j][i] == FlAG) {
                cout << "F";
                continue;
            }
            if (map[j][i] == BORDER) {
                cout << "#";
            } else if (map[j][i] == EMPTY_CELL) {
                cout << " ";
            } else if (map[j][i] == MINE) {
                cout << "*";
            } else if (map[j][i] >= 1 && map[j][i] <= 8) {
                cout << map[j][i];
            }


        }
        cout << endl;
    }


}

Map::GameStatus Map::check(int x, int y) {
    int numbOfOpenedCells = 0;
    int numbOfFlags = 0;
    for (int i = 1; i < getSize() - 1; i++) {
        for (int j = 1; j < getSize() - 1; j++) {
            if (mask[j][i] == 1)
                numbOfOpenedCells += mask[j][i];
            if (mask[j][i] == FlAG && map[j][i] == MINE)
                numbOfFlags++;
        }
    }
    if (numbOfFlags == getMines()) {
        return Win;
    }

    if (map[x][y] == MINE && mask[x][y] == 1) {
        return Lose;
    } else if (((size - 2) * (size - 2)) - mines == numbOfOpenedCells) {
        return Win;
    } else return inProgress;
}

int Map::setFlag(int x, int y) {

    if (mask[x][y] == FlAG) {
        mask[x][y] = EMPTY_CELL;
        counterFlags--;
    } else if (mask[x][y] == EMPTY_CELL) {
        mask[x][y] = FlAG;
        counterFlags++;
    }
    return counterFlags;
}

bool Map::checkFlag(int x, int y) {
    return mask[x][y] != FlAG;
}
