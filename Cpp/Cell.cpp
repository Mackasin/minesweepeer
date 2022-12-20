//
// Created by maxsd on 20.12.2022.
//

#include "../Headers/Cell.h"

Cell::Cell(char type) : type(type) {}

Cell::~Cell() {

}

char Cell::getType() const {
    return type;
}
