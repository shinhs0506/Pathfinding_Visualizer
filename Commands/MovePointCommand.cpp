#include "MovePointCommand.h"

MovePointCommand::MovePointCommand(Grid *grid, std::pair<int, int> from, std::pair<int ,int> to) {
    this->grid = grid;
    this->fromRow = from.first;
    this->fromCol = from.second;
    this->toRow = to.first;
    this->toCol = to.second;
}

void MovePointCommand::execute() {
    grid->move(fromRow, fromCol, toRow, toCol);
}
