#include "Grid.h"

Grid::Grid() {

}

bool Grid::isEmpty(int row, int col) {
    return grid[row][col] == EMPTY;
}

bool Grid::isStart(int row, int col){
    return row == start.first && col == start.second;
}

bool Grid::isFinish(int row, int col){
    return row == finish.first && col == finish.second;
}

bool Grid::isWall(int row, int col){
    return grid[row][col] == WALL;
}

bool Grid::isExplored(int row, int col){
    return grid[row][col] == EXPLORED;
}

bool Grid::isShortestPath(int row, int col){
    return grid[row][col] == SHORTESTPATH;
}

void Grid::setEmpty(int row, int col) {
    grid[row][col] = EMPTY;
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
    grid[row][col] = WALL;
}

void Grid::setExplored(int row, int col){
    grid[row][col] = EXPLORED;
}

void Grid::setShortestPath(int row, int col){
    grid[row][col] = SHORTESTPATH;
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

void Grid::clear() {
    for (int i = 0; i < this->grid.size(); i++) {
        for (int j = 0; j < this->grid[0].size(); j++){
            if (isExplored(i, j) || isShortestPath(i, j)) {
                setEmpty(i, j);
            }
        }
    }
}

void Grid::reset() {
    for (int i = 0; i < this->grid.size(); i++){
        for (int j = 0; j < this->grid[0].size(); j++){
            setEmpty(i, j);
        }
    }
    resetStart();
    resetFinish();
}

void Grid::resetStart() {
    start = defaultStart;
}

void Grid::resetFinish() {
    finish = defaultFinish;
}

void Grid::move(int fromRow, int fromCol, int toRow, int toCol) {
    int toVal = grid[toRow][toCol];
    
    if (toVal != WALL) {
        if (isStart(fromRow, fromCol) && !isFinish(toRow, toCol)) {
            this->setStart(toRow, toCol);
        }
        if (isFinish(fromRow, fromCol) && !isStart(toRow, toCol)) {
            this->setFinish(toRow, toCol);
        }
    }

}
