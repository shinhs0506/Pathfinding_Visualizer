#include "Utility.h"

const std::vector<std::pair<int, int>> Utility::dirs = {std::make_pair(0, 1), std::make_pair(1, 0), std::make_pair(0, -1), std::make_pair(-1, 0)};

bool Utility::isInbound(std::vector<std::vector<int>> grid, std::pair<int, int> cell){
    if (cell.first < 0 || cell.second < 0) return false;
    if (cell.first >= grid.size() || cell.second >= grid[0].size()) return false;
    return true;
}
