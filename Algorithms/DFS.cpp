#include "DFS.h"

Path DFS::solve(Grid *grid) 
{
    std::pair<int, int> start = grid->getStart();
    std::pair<int, int> finish = grid->getFinish();
    std::vector<std::vector<int>> board = grid->getGrid();
    std::vector<std::pair<int, int>> explored;
    std::stack<std::vector<std::pair<int, int>>> s;

    //std::cout << start.first << " " << start.second << std::endl;
    //std::cout << finish.first << " " << finish.second << std::endl;

    s.push({start});
    grid->setExplored(start.first, start.second);

    while (!s.empty()) {
        std::vector<std::pair<int, int>> front = s.top();
        s.pop();

        std::pair<int, int> last = front[front.size() - 1];

        if (grid->isFinish(last.first, last.second)) {
            Path successPath = {explored, front};
            return successPath;
        }

        for (std::pair<int, int> dir : Utility::dirs) {
            std::pair<int, int> neighbour;
            neighbour.first = last.first + dir.first;
            neighbour.second = last.second + dir.second;

            if (Utility::isInbound(board, neighbour) && grid->isEmpty(neighbour.first, neighbour.second)) {
                std::vector<std::pair<int, int>> newFront(front);
                newFront.push_back(neighbour);
                s.push(newFront);

                explored.push_back(last);
                grid->setExplored(last.first, last.second);

                std::cout << "expor " << last.first << " " << last.second << std::endl;

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
