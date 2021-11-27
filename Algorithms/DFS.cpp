#include "DFS.h"

bool DFS::isInbound(std::vector<std::vector<int>> grid, std::pair<int, int> cell) 
{
    if (cell.first < 0 || cell.second < 0) return false;
    if (cell.first >= grid.size() || cell.second >= grid[0].size()) return false;
    return true;
}

Path DFS::solve(Grid grid) 
{
    std::pair<int, int> start = grid.getStart();
    std::pair<int, int> finish = grid.getFinish();
    std::vector<std::vector<int>> board = grid.getGrid();
    std::vector<std::pair<int, int>> explored;
    std::stack<std::vector<std::pair<int, int>>> s;

    //std::cout << start.first << " " << start.second << std::endl;
    //std::cout << finish.first << " " << finish.second << std::endl;

    std::vector<std::pair<int, int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    for (std::pair<int, int> dir : dirs) {
        std::pair<int, int> neighbour;
        neighbour.first = start.first + dir.first;
        neighbour.second = start.second + dir.second;
        s.push({neighbour});
    }

    while (!s.empty()) {
        std::vector<std::pair<int, int>> front = s.top();
        s.pop();

        std::pair<int, int> last = front[front.size() - 1];

        if (isInbound(board, last) && grid.isEmpty(last.first, last.second)) {
            explored.push_back(last);
            grid.setExplored(last.first, last.second);

            std::cout << "expor " << last.first << " " << last.second << std::endl;

            if (grid.isFinish(last.first, last.second)) {
                Path successPath = {explored, front};
                return successPath;
            }
            for (std::pair<int, int> dir : dirs) {
                std::pair<int, int> neighbour;
                neighbour.first = last.first + dir.first;
                neighbour.second = last.second + dir.second;

                std::vector<std::pair<int, int>> newFront(front);
                newFront.push_back(neighbour);
                s.push(newFront);
            }
        }
    }

    std::cout << "failed" << std::endl;
    Path failPath = {
        explored,
        {},
    };
    return failPath;
}
