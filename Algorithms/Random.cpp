#include "Random.h"

bool Random::isInbound(std::vector<std::vector<int>> grid, std::pair<int, int> cell) 
{
    if (cell.first < 0 || cell.second < 0) return false;
    if (cell.first >= grid.size() || cell.second >= grid[0].size()) return false;
    return true;
}

Path Random::solve(Grid grid){
    std::pair<int, int> start = grid.getStart();
    std::pair<int, int> finish = grid.getFinish();
    std::vector<std::vector<int>> board = grid.getGrid();
    std::vector<std::pair<int, int>> explored;
    std::queue<std::vector<std::pair<int, int>>> q;

    std::vector<std::pair<int, int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    q.push({start});
    grid.setExplored(start.first, start.second);
    while (!q.empty()) {
        std::vector<std::pair<int, int>> front = q.front();
        q.pop();

        std::pair<int, int> last = front[front.size() - 1];


        int random = rand();
        int d = random % 4;
        std::cout << d << std::endl;
        std::pair<int, int> dir = dirs[d];
        std::pair<int, int> neighbour;
        neighbour.first = last.first + dir.first;
        neighbour.second = last.second + dir.second;

        if (isInbound(board, neighbour) && grid.isEmpty(neighbour.first, neighbour.second)) {
            std::vector<std::pair<int, int>> newFront(front);
            newFront.push_back(neighbour);
            q.push(newFront);

            explored.push_back(neighbour);
            grid.setExplored(neighbour.first, neighbour.second);

            std::cout << "expor " << last.first << " " << last.second << std::endl;

            if (grid.isFinish(neighbour.first, neighbour.second)) {
                
                std::cout << "found" << std::endl;
                Path successPath = {explored, newFront};
                return successPath;
            }
        }

        bool found = false;
        for (std::pair<int, int> dir : dirs) {
            std::pair<int, int> neighbour;
            neighbour.first = last.first + dir.first;
            neighbour.second = last.second + dir.second;
            if (isInbound(board, neighbour) && !grid.isWall(neighbour.first, neighbour.second) && !grid.isExplored(neighbour.first, neighbour.second)) {
                found = true; 
                break;
            }
        }

        if (found) {
            q.push(front);
        }
    }

    std::cout << "failed" << std::endl;
    Path failPath = {
        explored,
        {},
    };
    return failPath;
}
