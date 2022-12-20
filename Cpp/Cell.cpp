
#include "../Headers/Cell.h"

Cell::CellState Cell::getCellState() const {
    return cellState;
}


Cell::Cell(Cell::CellState cellState) : cellState(cellState) {}
