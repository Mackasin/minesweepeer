//
// Created by maxsd on 20.12.2022.
//

#ifndef MINESWEEPPER_CELL_H
#define MINESWEEPPER_CELL_H


class Cell {
protected:
    enum CellState{
        OPEN,CLOSED,FLAG
    };
   char type;
public:
    Cell(char type);

    char getType() const;

    virtual ~Cell();
};


#endif //MINESWEEPPER_CELL_H
