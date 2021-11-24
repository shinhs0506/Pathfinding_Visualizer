#include "Grid.h"

Grid::Grid() {

}

bool Grid::isStart(int row, int col){
    return row == start.first && col == start.second;
}

bool Grid::isFinish(int row, int col){
    return row == finish.first && col == finish.second;
}

bool Grid::isWall(int row, int col){
    // TODO: expose constants
    return grid[row][col] == 3;
}

bool Grid::isExplored(int row, int col){
    // TODO: expose constants
    return grid[row][col] == 4;
}

bool Grid::isShortestPath(int row, int col){
    // TODO: expose constants
    return grid[row][col] == 5;
}

void Grid::setStart(int row, int col){
    start.first = row;
    start.second = col;
}

void Grid::setFinish(int row, int col){
    finish.first = row;
    finish.second = col;
}

void Grid::setWall(int row, int col){
    // TODO: expose constants
    grid[row][col] = 3;
}

void Grid::setExplored(int row, int col){
    // TODO: expose constants
    grid[row][col] = 4;
}

void Grid::setShortestPath(int row, int col){
    // TODO: expose constants
    grid[row][col] = 5;
}

void Grid::resize(int rows, int cols) {
    grid.resize(rows);
    for (std::vector<int>& row : grid) {
        row.resize(cols);
    }
}

std::pair<int, int> Grid::getStart() {
    return start;
}

std::pair<int, int> Grid::getFinish(){
    return finish;
}

std::vector<std::vector<int>> Grid::getGrid(){
    return grid;
}
