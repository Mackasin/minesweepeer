#ifndef MINESWEEPPER_CURSOR_H
#define MINESWEEPPER_CURSOR_H


class Cursor {
private:
    int x = 1;
    int y = 1;
    int tx = 1;
    int ty = 1;
public:
    void save();

    void undo();

    void incX();

    void incY();

    void decX();

    void decY();

    int getX();

    int getY();
};


#endif //MINESWEEPPER_CURSOR_H
