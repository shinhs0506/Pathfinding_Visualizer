#ifndef MOVEPOINTCOMMAND_H
#define MOVEPOINTCOMMAND_H

#include "Command.h"

class MovePointCommand: public Command {
    public:
        MovePointCommand();
        void execute() override;
};

#endif
