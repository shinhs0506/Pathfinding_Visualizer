#ifndef GRID_H
#define GRID_H

#include <vector>
#include <utility>

class Grid {

    private:
        std::vector<std::vector<int>> grid;
        std::pair<int, int> start;
        std::pair<int, int> finish;

    public: 
        Grid();
        bool isStart(int row, int col);
        bool isFinish(int row, int col);
        bool isWall(int row, int col);
        bool isExplored(int row, int col);
        bool isShortestPath(int row, int col);
        void setStart(int row, int col);
        void setFinish(int row, int col);
        void setWall(int row, int col);
        void setExplored(int row, int col);
        void setShortestPath(int row, int col);
        std::pair<int, int> getStart();
        std::pair<int, int> getFinish();
        std::vector<std::vector<int>> getGrid();
        void resize(int rows, int cols);
};

#endif
