#include<QWidget>
#include<QRect>
#include<QPainter>
#include<QColor>

#include<iostream>
using namespace std;

const int CELLSIZE = 20;

class Board : public QWidget {
    
    public:
        Board();

    protected:
        void paintEvent(QPaintEvent *event) override;

    private:
        int boardWidth;
        int boardHeight;
        int cellSize;
};

Board::Board() {
    boardWidth = this->width();
    boardHeight = this->height(); 
}

void Board::paintEvent(QPaintEvent *e) {
    QPainter painter(this);
    QPen pen("white");
    pen.setWidth(2);
    painter.setPen(pen);

    int rows = boardHeight / CELLSIZE;
    int cols = boardWidth / CELLSIZE;

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            painter.drawRect(j * CELLSIZE, i * CELLSIZE, CELLSIZE, CELLSIZE);
        }
    }
}
