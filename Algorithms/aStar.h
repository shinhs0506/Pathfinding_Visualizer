#ifndef ASTAR_H
#define ASTAR_H

#include "Algorithms.h"

class AStar : public Algorithms {
    public: 
        Path solve(Grid grid);
};

#endif
