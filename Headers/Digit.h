
#ifndef MINESWEEPPER_DIGIT_H
#define MINESWEEPPER_DIGIT_H
#include "Cell.h"

class Digit: public Cell{
public:
    void setDigit(int digit);

private:
    int digit=0;
};


#endif //MINESWEEPPER_DIGIT_H
