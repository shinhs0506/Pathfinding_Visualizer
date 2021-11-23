#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>
#include <utility>

#include "Path.h"

class Algorithms {
    public :
        virtual Path solve(
                std::vector<std::vector<int>> board, 
                std::pair<int, int> start, 
                std::pair<int, int> finish) = 0;
};

#endif
