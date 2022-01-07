#include "aStar.h"
#include <utility>

AStar::Node::Node(int r, int c, double g, double h, double f, std::pair<int, int> parent) {
    this->r = r;
    this->c = c;
    this->g = g;
    this->h = h;
    this->f = f;
    this->p = parent;
}

bool AStar::Node::operator!=(const Node& b) {
    return this->r != b.r || this->c != b.c;
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
    res.push_back(std::make_pair(curr.r, curr.c));
    
    return res;
}

Path AStar::solve(Grid *grid) {
    std::pair<int, int> start = grid->getStart();
    std::pair<int, int> finish = grid->getFinish();
    std::vector<std::vector<int>> board = grid->getGrid();

    // open list
    auto compare = [](const Node& a, const Node& b) {return a.f > b.f; };
    std::priority_queue<Node, std::vector<Node>, decltype(compare)> openList(compare);
    // closed list
    int rows = board.size();
    int cols = board[0].size();
    std::vector<std::pair<int, int>> visited;
    std::vector<std::vector<bool>> explored (rows, std::vector<bool>(cols, 0));
    std::vector<std::vector<Node>> closedList;
    for (int i = 0; i < board.size(); i++) {
        std::vector<Node> row;
        for (int j = 0; j < board[0].size(); j++) {
            Node n (i, j, std::numeric_limits<double>::max(), Utility::euclideanDistance(i, j, finish.first, finish.second), std::numeric_limits<double>::max(), std::make_pair(-1, -1));
            row.push_back(n);
        } 
        closedList.push_back(row);
    }

    Node& startNode = closedList[start.first][start.second];
    startNode.g = 0.0;
    startNode.f = startNode.g + startNode.h;
    startNode.p = std::make_pair(start.first, start.second);

    openList.push(startNode);

    while(!openList.empty()) {
        Node front = openList.top();
        openList.pop();

        explored[front.r][front.c] = true;
        
        for (std::pair<int, int> dir : Utility::dirs) {
            int r = front.r + dir.first;
            int c = front.c + dir.second;

            if (!Utility::isInbound(board, std::make_pair(r ,c)) || grid->isWall(r, c)) {
                continue;
            }
            if (explored[r][c]) continue;
            std::pair<int, int> p = std::make_pair(r, c);
            if (std::find(visited.begin(), visited.end(), p) == visited.end()) {
                visited.push_back(p);
            }

            Node& neighbour = closedList[r][c];

            if (grid->isFinish(r, c)) {
                // return result;
                std::cout << " finished " << std::endl;
                std::vector<std::pair<int, int>> shortest = generatePath(closedList, front);
                shortest.push_back(std::make_pair(start.first, start.second));
                reverse(shortest.begin(), shortest.end());
                return { visited, shortest };
            }

            double neighbourCost = front.g + 1.0;
            if (neighbour.g == std::numeric_limits<double>::max() ||  neighbourCost < neighbour.g) {
                neighbour.p = std::make_pair(front.r, front.c);
                neighbour.g = neighbourCost;
                neighbour.f = neighbourCost + neighbour.h;
                openList.push(neighbour);
            }
        } 
    }

    // failed
    std::cout << " failed " << std::endl;
    return { visited, {} };
}
