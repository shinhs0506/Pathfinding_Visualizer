#include "Utility.h"

const std::vector<std::pair<int, int>> Utility::dirs = {std::make_pair(0, 1), std::make_pair(1, 0), std::make_pair(0, -1), std::make_pair(-1, 0)};

bool Utility::isInbound(std::vector<std::vector<int>> grid, std::pair<int, int> cell){
    if (cell.first < 0 || cell.second < 0) return false;
    if (cell.first >= grid.size() || cell.second >= grid[0].size()) return false;
    return true;
}

double Utility::euclideanDistance(int x1, int y1, int x2, int y2) {
    double x = pow((double) abs(x2 - x1), 2.0);
    double y = pow((double) abs(y2 - y1), 2.0);
    return std::sqrt(x + y); 
}
