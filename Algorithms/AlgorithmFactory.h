#ifndef ALGORITHM_FACTORY_H
#define ALGORITHM_FACTORY_H

#include <QString>

#include "BFS.h"
#include "DFS.h"
#include "Random.h"

#include <iostream>

class AlgorithmFactory {
    public:
        AlgorithmFactory();
        Algorithms* switchAlgo(QString str);
};

#endif
