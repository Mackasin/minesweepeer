
#include "../Headers/Cursor.h"



void Cursor::save() {
    tx = x;
    ty = y;
}

void Cursor::undo() {
    x = tx;
    y = ty;
}

void Cursor::incX() {
    x++;
}

void Cursor::incY() {
    y++;
}

void Cursor::decX() {
    x--;
}

void Cursor::decY() {
    y--;
}

int Cursor::getX() {
    return x;
}

int Cursor::getY() {
    return y;
}
