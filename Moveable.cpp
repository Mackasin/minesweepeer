#include <windows.h>
#include <wincon.h>
#include "../Headers/Moveable.h"


void Moveable::gotoxy(int x, int y) {
    COORD p = {static_cast<SHORT>(x), static_cast<SHORT>(y)};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}
