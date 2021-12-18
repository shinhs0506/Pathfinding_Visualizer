#ifndef RANDOM_H
#define RANDOM_H

#include <queue> 
#include <stack>
#include <cstdlib>

#include "Algorithms.h"

#include <iostream>

class Random: public Algorithms {
    private:
        bool isInbound(std::vector<std::vector<int>> grid, std::pair<int, int> cell);

    public:
        Path solve(Grid grid) override;
};

#endif
