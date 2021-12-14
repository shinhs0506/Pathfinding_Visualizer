#ifndef PATH_H
#define PATH_H

#include <vector>
#include <utility>

class Path {
    private:
        std::vector<std::pair<int, int>> visited;
        std::vector<std::pair<int, int>> shortest;

    public:
        Path();
        Path(std::vector<std::pair<int,int>> visited, std::vector<std::pair<int,int>> shortest);
        int getVisitedPathSize();
        int getShortestPathSize(); 
        std::vector<std::pair<int,int>> getVisitedPath();
        std::vector<std::pair<int,int>> getShortestPath();
};

#endif
