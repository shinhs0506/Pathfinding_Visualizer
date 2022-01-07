#ifndef RANDOM_H
#define RANDOM_H

#include <queue> 
#include <stack>
#include <cstdlib>

#include "Algorithms.h"

#include <iostream>

class Random: public Algorithms {
    public:
        Path solve(Grid *grid) override;
};

#endif
