#ifndef MOVEPOINTCOMMAND_H
#define MOVEPOINTCOMMAND_H

#include "Command.h"
#include "../Grid.h"

class MovePointCommand: public Command {
    private:
        Grid* grid;
        int fromRow;
        int fromCol;
        int toRow;
        int toCol;

    public:
        MovePointCommand(int fromRow, int fromCol, int toRow, int toCol);
        void execute() override;
};

#endif
