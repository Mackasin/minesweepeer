
#ifndef MINESWEEPPER_DIGIT_H
#define MINESWEEPPER_DIGIT_H


#include "Cell.h"

class Digit : public Cell{
public:
    int digit=0;

    Digit(int digit);
};


#endif //MINESWEEPPER_DIGIT_H
