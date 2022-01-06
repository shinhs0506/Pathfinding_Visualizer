#include "MovePointCommand.h"

MovePointCommand::MovePointCommand(int fromRow, int fromCol, int toRow, int toCol) {
    this->fromRow = fromRow;
    this->fromCol = fromCol;
    this->toRow = toRow;
    this->toCol = toCol;
}

void MovePointCommand::execute() {
    grid->swap(fromRow, fromCol, toRow, toCol);
}
