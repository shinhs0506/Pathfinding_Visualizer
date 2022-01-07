#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>
#include <utility>

#include "../Path.h"
#include "../Grid.h"
#include "Utility.h"


class Algorithms {
    public :
        virtual Path solve(Grid *grid) = 0;
};

#endif
