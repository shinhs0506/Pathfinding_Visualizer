#include "BFS.h"

Path BFS::solve(Grid grid) 
{
    std::pair<int, int> start = grid.getStart();
    std::pair<int, int> finish = grid.getFinish();
    std::vector<std::vector<int>> board = grid.getGrid();
    std::vector<std::pair<int, int>> explored;
    std::queue<std::vector<std::pair<int, int>>> q;

    //std::cout << start.first << " " << start.second << std::endl;
    //std::cout << finish.first << " " << finish.second << std::endl;

    for (std::pair<int, int> dir : Utility::dirs) {
        std::pair<int, int> neighbour;
        neighbour.first = start.first + dir.first;
        neighbour.second = start.second + dir.second;
        q.push({neighbour});
    }

    while (!q.empty()) {
        std::vector<std::pair<int, int>> front = q.front();
        q.pop();

        std::pair<int, int> last = front[front.size() - 1];

        if (Utility::isInbound(board, last) && grid.isEmpty(last.first, last.second)) {
            explored.push_back(last);
            grid.setExplored(last.first, last.second);

            std::cout << "expor " << last.first << " " << last.second << std::endl;

            if (grid.isFinish(last.first, last.second)) {
                Path successPath = {explored, front};
                return successPath;
            }
            for (std::pair<int, int> dir : Utility::dirs) {
                std::pair<int, int> neighbour;
                neighbour.first = last.first + dir.first;
                neighbour.second = last.second + dir.second;

                std::vector<std::pair<int, int>> newFront(front);
                newFront.push_back(neighbour);
                q.push(newFront);
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
