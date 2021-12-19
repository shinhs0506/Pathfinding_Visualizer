#ifndef BFS_H
#define BFS_H

#include <queue>

#include "Algorithms.h"

#include <iostream>

class BFS : public Algorithms {
    public:
        Path solve(Grid grid) override;
};

#endif
