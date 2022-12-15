
#include <conio.h>


#include "../Headers/Keyboard.h"

Keyboard::Keyboard() {
    ch = 0;
}

void Keyboard::waitKey() {
    ch = _getch();
}

int Keyboard::getKey() {
    return ch;
}
