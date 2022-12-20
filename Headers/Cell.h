
#ifndef MINESWEEPPER_CELL_H
#define MINESWEEPPER_CELL_H


#include <ostream>
#include "Mine.h"

class Cell{

public:
    enum CellState{
        OPEN,
        CLOSED,
        FLAG
    };


private:
    CellState cellState=CLOSED;

public:
    CellState getState();

    Cell(CellState cellState);

    CellState getCellState() const;
};


#endif //MINESWEEPPER_CELL_H
