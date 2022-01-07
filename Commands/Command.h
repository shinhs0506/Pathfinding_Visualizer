#ifndef COMMAND_H
#define COMMAND_H

#include "../Grid.h"

class Command {
    protected:
        Grid* grid;
    public:
        virtual void execute() = 0;
};

#endif
