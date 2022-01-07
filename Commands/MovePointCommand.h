#ifndef MOVEPOINTCOMMAND_H
#define MOVEPOINTCOMMAND_H

#include "Command.h"

class MovePointCommand: public Command {
    private:
        int fromRow;
        int fromCol;
        int toRow;
        int toCol;

    public:
        MovePointCommand(int fromRow, int fromCol, int toRow, int toCol);
        void execute() override;
};

#endif
