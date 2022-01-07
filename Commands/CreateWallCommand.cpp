#include "CreateWallCommand.h"

CreateWallCommand::CreateWallCommand(std::vector<std::pair<int, int>> points) {
    this->points = points;
}

void CreateWallCommand::execute() {
    for (std::pair<int, int> &point : points) {
        grid->setWall(point.first, point.second);
    }
}
