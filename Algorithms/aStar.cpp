#include "aStar.h"
#include <limits>
#include <utility>

AStar::Node::Node(int r, int c, int g, int h, int f, std::pair<int, int> parent) {
    this->r = r;
    this->c = c;
    this->g = g;
    this->h = h;
    this->f = f;
    this->p = parent;
}

bool AStar::Node::operator!= (const Node& b) {
    return this->r == b.r && this->c == b.c;
} 

std::vector<std::pair<int, int>> AStar::generatePath(std::vector<std::vector<Node>> closedList, Node n) {
    Node curr = n;
    Node parent = closedList[curr.p.first][curr.p.second];
    std::vector<std::pair<int, int>> res;
    while (parent != curr) {
        res.push_back(std::make_pair(curr.r, curr.c));
        curr = parent;
        parent = closedList[parent.p.first][parent.p.second];
    }
    
    return res;
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
    //auto hash = [](const Node& n) {return h()(n.x) + (h()(n.y) * 100);};
    //auto equal = [](const Node& a, const Node& b) {return a.x == b.x && a.y == b.y;};
    //std::unordered_set<Node, decltype(hash), decltype(equal)> closedSet(10, hash, equal);
    // visited list
    std::vector<std::pair<int, int>> visited;
    std::vector<std::vector<Node>> closedList;
    for (int i = 0; i < board.size(); i++) {
        std::vector<Node> row;
        for (int j = 0; j < board[0].size(); j++) {
            Node n (i, j, 0, std::numeric_limits<int>::max(), std::numeric_limits<int>::max(), std::make_pair(-1, -1));
            row.push_back(n);
        } 
        closedList.push_back(row);
    }

    int startEuclidean = euclideanDistance(start.first, start.second, finish.first, finish.second);
    Node startNode = closedList[start.first][start.second];
    startNode.f = 0;
    startNode.g = startEuclidean;
    startNode.h = startNode.f + startNode.g;
    openSet.insert(startNode);

    while(!openSet.empty()) {
        std::set<Node>::iterator frontIt = openSet.begin();
        Node front = *frontIt;
        openSet.erase(frontIt);

        for (std::pair<int, int> dir : Utility::dirs) {
            int r = front.r + dir.first;
            int c = front.c + dir.second;
            Node neighbour = closedList[r][c];

            if (grid.isWall(r, c)) {
                continue;
            }

            visited.push_back(std::make_pair(r, c));

            if (grid.isFinish(r, c)) {
                // return result;
                std::vector<std::pair<int, int>> shortest = generatePath(closedList, front);
                return { shortest, visited };
            }

            int neighbourCost = front.g + 1;

            std::set<Node>::iterator openIt = openSet.find(neighbour);
            Node closedIt = closedList[r][c];
            if (openIt != openSet.end()) {
                if (openIt->g < neighbourCost) {
                    continue;    
                }
            } else if (closedIt.g != std::numeric_limits<int>::max()) {
                if (closedIt.g < neighbourCost) {
                    continue;
                } else {
                    openSet.insert(closedIt);
                }
            } else {
                openSet.insert(neighbour);
                neighbour.h = euclideanDistance(neighbour.r, neighbour.c, finish.first ,finish.second);
            }

            neighbour.g = neighbourCost;
            neighbour.f = neighbour.g + neighbour.h;
            neighbour.p = std::make_pair(front.r, front.c); 
        } 
    }

    // failed
    return { {}, visited };
}
