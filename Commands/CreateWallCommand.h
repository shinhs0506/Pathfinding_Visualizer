#ifndef CREATEWALLCOMMAND_H
#define CREATEWALLCOMMAND_H

#include "Command.h"

class CreateWallCommand: public Command {
    public:
        CreateWallCommand();
        void execute() override;
};

#endif
