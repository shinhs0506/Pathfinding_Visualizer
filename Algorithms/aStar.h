#ifndef ASTAR_H
#define ASTAR_H

#include <queue>
#include <limits>
#include <algorithm>

#include "Algorithms.h"

#include <iostream>

class AStar : public Algorithms {
    private:
        class Node {
            public:
                int r;
                int c;
                double g;
                double h;
                double f;
                std::pair<int, int> p;
                Node();
                Node(int r, int c, double g, double h, double f, std::pair<int, int> p);
                bool operator!=(const Node& b);
        };
        std::vector<std::pair<int, int>> generatePath(std::vector<std::vector<Node>> closedList, Node n);

    public: 
        Path solve(Grid grid);
};

#endif
