#include "CreateWallCommand.h"

CreateWallCommand::CreateWallCommand(Grid *grid, std::vector<std::pair<int, int>> points) {
    this->grid = grid;
    this->points = points;
}

void CreateWallCommand::execute() {
    for (std::pair<int, int> &point : points) {
        grid->setWall(point.first, point.second);
    }
}
