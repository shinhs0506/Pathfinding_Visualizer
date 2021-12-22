#include "aStar.h"

AStar::Node::Node(int x, int y, int g, int h, int f) {
    this->x = x;
    this->y = y;
    this->g = g;
    this->h = h;
    this->f = f;
}

Path AStar::solve(Grid grid) {
    std::pair<int, int> start = grid.getStart();
    std::pair<int, int> finish = grid.getFinish();
    std::vector<std::vector<int>> board = grid.getGrid();

    // open list
    std::set<Node> openSet;
    // closed list
    using h = std::hash<int>;
    int size = board.size();
    // TODO: come up with a better hash function
    auto hash = [](const Node& n) {return h()(n.x) + (h()(n.y) * 100);};
    auto equal = [](const Node& a, const Node& b) {return a.x == b.x && a.y == b.y;};
    std::unordered_set<Node, decltype(hash), decltype(equal)> closedSet(10, hash, equal);

    while(!openSet.empty()) {
        std::set<Node>::iterator frontIt = openSet.begin();
        Node front = *frontIt;
        openSet.erase(frontIt);

        for (std::pair<int, int> dir : Utility::dirs) {
            Node neighbour;
            neighbour.x = front.x + dir.first;
            neighbour.y = front.y + dir.second;

            if (grid.isFinish(neighbour.x, neighbour.y)) {
                // return result;
            }

            neighbour.g = front.g + 1;
            neighbour.h = euclideanDistance(neighbour.x, neighbour.y, finish.first ,finish.second);
            neighbour.f = neighbour.g + neighbour.h;

            std::set<Node>::iterator openIt = openSet.find(neighbour);
            if (openIt != openSet.end() && openIt->f < neighbour.f) {
                continue;    
            }

            std::unordered_set<Node>::iterator closedIt = closedSet.find(neighbour);
            if (closedIt != closedSet.end() && closedIt->f < neighbour.f) {
                continue;
            } else {
                openSet.insert(neighbour);
            }
        } 

        closedSet.insert(front);
    }
}
