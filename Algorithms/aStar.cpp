#include "aStar.h"

Path AStar::solve(Grid grid) {
    std::pair<int, int> start = grid.getStart();
    std::pair<int, int> finish = grid.getFinish();
    std::vector<std::vector<int>> board = grid.getGrid();

    // open list
    set<Node> openSet;
    // closed list
    unordered_set<Node> closedSet;

    while(!openSet.empty()) {
        Node front = openSet.front();
        openSet.pop_front();

        for (std::pair<int, int> dir : Utility::dirs) {
            Node neighbour;
            neighbour.x = front.x + dir.first;
            neighbour.y = front.y + dir.second;

            if (grid.isFinish(neighbour.first, neighbour.second)) {
                // return result;
            }

            neighbour.g = front.g + 1;
            neighbour.h = euclideanDistance(neighbour.x, neighbour.y, finish.first ,finish.second);
            neighbour.f = neighbour.g + neighbour.h;

            set<Node>::iterator openIt = openSet.find(neighbour);
            if (openIt != openSet.end() && openIt->f < neighbour.f) {
                continue;    
            }

            set<Node>::iterator closedIt = closedSet.find(neighbour);
            if (closedIt != closedSet.end() && closedIt->f < neighbour.f) {
                continue;
            } else {
                openSet.insert(neighbour);
            }
        } 

        closedSet.insert(front);
    }
}
