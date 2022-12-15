#include <iostream>
#include "../Headers/Game.h"

using namespace std;

int main() {
    srand(time(0));
    Game game;
    game.run();
    system("pause");
}