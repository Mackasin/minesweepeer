
#ifndef MINESWEEPPER_KEYBOARD_H
#define MINESWEEPPER_KEYBOARD_H


class Keyboard {
private:
    int ch;
public:
    Keyboard();

    void waitKey();

    int getKey();
};


#endif //MINESWEEPPER_KEYBOARD_H
