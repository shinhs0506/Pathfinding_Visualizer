#include <queue>

#include "Algorithms.h"

class BFS : public Algorithms {
    private:
        bool isInbound(std::vector<std::vector<int>> board, std::pair<int, int> cell);
        bool isEmpty(std::vector<std::vector<int>> board, std::pair<int, int> cell);

    public:
        std::vector<std::pair<int, int>> solve(
                std::vector<std::vector<int>> board,
                std::pair<int, int> &start,
                std::pair<int, int> &finish);
};

bool BFS::isInbound(std::vector<std::vector<int>> board, std::pair<int, int> cell) {
    if (cell.first < 0 || cell.second < 0) return false;
    if (cell.first >= board.size() || cell.second >= board[0].size()) return false;
    return true;
}

bool BFS::isEmpty(std::vector<std::vector<int>> board, std::pair<int, int> cell) {
    return board[cell.first][cell.second] == 0;
}

std::vector<std::pair<int, int>> BFS::solve(
    std::vector<std::vector<int>> board,
    std::pair<int, int> &start,
    std::pair<int, int> &finish) 
{
    std::vector<std::pair<int, int>> res;
    std::queue<std::vector<std::pair<int, int>>> q;
    q.push({start});

    std::vector<std::pair<int, int>> dirs = {{0,1}, {0,-1}, {-1,0}, {1,0}};
    while(!q.empty()){
        std::vector<std::pair<int, int>> front = q.front();
        q.pop();

        std::pair<int, int> last = front[front.size() - 1];
        if (last.first == finish.first && last.second == finish.second) {
            return front;
        }
        for (std::pair<int, int> dir : dirs ) {
            std::pair<int, int> neighbour;
            neighbour.first = last.first + dir.first;
            neighbour.second = last.second + dir.second;

            if (isInbound(board, neighbour) && isEmpty(board, neighbour)) {
                std::vector<std::pair<int, int>> newFront (front);
                newFront.push_back(neighbour);
                q.push(newFront);
            }
        }
    }
    return res;
}


