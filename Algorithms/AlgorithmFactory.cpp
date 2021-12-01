#include "AlgorithmFactory.h"

AlgorithmFactory::AlgorithmFactory() {

}

Algorithms* AlgorithmFactory::switchAlgo(QString str) {
    std::string algoStr = str.toStdString();
    Algorithms* algo;
    if (algoStr == "BFS") {
        std::cout << "BFS selected " << std::endl;
        algo = new BFS(); 
    } else if (algoStr == "DFS") {
        std::cout << "DFS selected " << std::endl;
        algo = new DFS();
    }
    return algo;
}


