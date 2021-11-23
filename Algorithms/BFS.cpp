#ifndef BFS_H
#define BFS_H

#include <queue>

#include "Algorithms.h"

#include <iostream>

class BFS : public Algorithms {
    private:
        bool isInbound(std::vector<std::vector<int>> board, std::pair<int, int> cell);
        bool isEmpty(std::vector<std::vector<int>> board, std::pair<int, int> cell);

    public:
        Path solve(
                std::vector<std::vector<int>> board,
                std::pair<int, int> start,
                std::pair<int, int> finish) override;
};

bool BFS::isInbound(std::vector<std::vector<int>> board, std::pair<int, int> cell) 
{
    if (cell.first < 0 || cell.second < 0) return false;
    if (cell.first >= board.size() || cell.second >= board[0].size()) return false;
    return true;
}

bool BFS::isEmpty(std::vector<std::vector<int>> board, std::pair<int, int> cell) 
{
    return board[cell.first][cell.second] == 0;
}

Path BFS::solve(
        std::vector<std::vector<int>> board,
        std::pair<int, int> start,
        std::pair<int, int> finish) 
{
    std::vector<std::pair<int, int>> explored;
    std::queue<std::vector<std::pair<int, int>>> q;

    std::cout << start.first << " " << start.second << std::endl;
    std::cout << finish.first << " " << finish.second << std::endl;

    std::vector<std::pair<int, int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    for (std::pair<int, int> dir : dirs) {
        std::pair<int, int> neighbour;
        neighbour.first = start.first + dir.first;
        neighbour.second = start.second + dir.second;
        q.push({neighbour});
    }

    while (!q.empty()) {
        std::vector<std::pair<int, int>> front = q.front();
        q.pop();

        std::pair<int, int> last = front[front.size() - 1];

        if (isInbound(board, last) && isEmpty(board, last)) {
            explored.push_back(last);
            // TODO: better exploration mechanism
            board[last.first][last.second] = 1;

            std::cout << "expor " << last.first << " " << last.second << std::endl;

            if (last.first == finish.first && last.second == finish.second) {
                Path successPath = {explored, front};
                return successPath;
            }
            for (std::pair<int, int> dir : dirs) {
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

#endif
