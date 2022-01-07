#ifndef CREATEWALLCOMMAND_H
#define CREATEWALLCOMMAND_H

#include "Command.h"

class CreateWallCommand: public Command {
    private:
        std::vector<std::pair<int, int>> points;

    public:
        CreateWallCommand(Grid* grid, std::vector<std::pair<int, int>> points);
        void execute() override;
};

#endif
