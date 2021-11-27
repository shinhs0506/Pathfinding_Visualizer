#ifndef DFS_H
#define DFS_H

#include <stack>

#include "Algorithms.h"

#include <iostream>

class DFS : public Algorithms {
    private:
        bool isInbound(std::vector<std::vector<int>> grid, std::pair<int, int> cell);

    public:
        Path solve(Grid grid) override;
};

#endif
