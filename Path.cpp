#include "Path.h"

Path::Path() {

}

Path::Path(std::vector<std::pair<int,int>> visited, std::vector<std::pair<int,int>> shortest) {
    this->visited = visited;
    this->shortest = shortest;
}

int Path::getVisitedPathSize() {
    return this->visited.size();
}

int Path::getShortestPathSize() {
    return this->shortest.size();
}

std::vector<std::pair<int,int>> Path::getVisitedPath() {
    return this->visited;
}

std::vector<std::pair<int,int>> Path::getShortestPath() {
    return this->shortest;
}
