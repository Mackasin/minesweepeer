
#include "../Headers/Game.h"
#include "../Headers/Map.h"
#include "../Headers/Moveable.h"


void Game::run() {

    Map::GameStatus game = Map::inProgress;
    Map map;
    map.initMap();
    map.setMines(map.getMines());
    map.setDigits();
    map.show();

    Moveable::gotoxy(1, 1);

    while (game == Map::inProgress) {
        keyboard.waitKey();
        cursor.save();
        switch (keyboard.getKey()) {
            case 77:
                cursor.incX();
                break;
            case 80:
                cursor.incY();
                break;
            case 75:
                cursor.decX();
                break;
            case 72:
                cursor.decY();
                break;
            case 13:
                map.setFlag(cursor.getX(), cursor.getY());
                map.show();
                game = map.check(cursor.getX(), cursor.getY());
                break;
            case 32:
                if (map.checkFlag(cursor.getX(), cursor.getY())) {
                    map.openCell(cursor.getX(), cursor.getY());
                    if (map.openCell(cursor.getX(), cursor.getY()) == 0) {
                        map.revealEmptyCell(cursor.getX(), cursor.getY());
                    }
                    map.show();
                    game = map.check(cursor.getX(), cursor.getY());
                }

                break;
        }
        if (map.isBorder(cursor.getX(), cursor.getY())) {
            cursor.undo();
        }
       Moveable::gotoxy(cursor.getX(), cursor.getY());
    }
    Moveable::gotoxy(map.getSize() - 1, map.getSize() - 1);
    switch (game) {
        case Map::Lose:
            cout << "\nYou Lose\n";
            break;
        case Map::Win:
            cout << "\nYou Win\n";
            break;
    }
}