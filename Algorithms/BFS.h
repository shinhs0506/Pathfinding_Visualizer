#ifndef BFS_H
#define BFS_H

#include <queue>

#include "Algorithms.h"

#include <iostream>

class BFS : public Algorithms {
    private:
        bool isInbound(std::vector<std::vector<int>> grid, std::pair<int, int> cell);
        bool isEmpty(std::vector<std::vector<int>> grid, std::pair<int, int> cell);

    public:
        Path solve(Grid grid) override;
};

#endif
