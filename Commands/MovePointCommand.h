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
        MovePointCommand(Grid *grid, std::pair<int ,int> from, std::pair<int, int> to);
        void execute() override;
};

#endif
