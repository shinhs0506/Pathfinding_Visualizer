#ifndef ASTAR_H
#define ASTAR_H

#include <set>
#include <unordered_set>

#include "Algorithms.h"

class AStar : public Algorithms {
    private:
        class Node {
            public:
                int x;
                int y;
                int g;
                int h;
                int f;
                Node();
                Node(int x, int y, int g, int h, int f);
        };
    public: 
        Path solve(Grid grid);
};

#endif
