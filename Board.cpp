#include<QWidget>
#include<QRect>
#include<QPainter>
#include<QColor>
#include<QMouseEvent>
#include<QPoint>

#include<iostream>

const int CELLSIZE = 20;

class Board : public QWidget {
    
    private:
        int getBoardWidth();
        int getBoardHeight();

    protected:
        void paintEvent(QPaintEvent *ev) override;
        void mousePressEvent(QMouseEvent *ev) override;

    public:
        Board();

};

Board::Board() {
}

int Board::getBoardHeight() {
    return this->height();
}

int Board::getBoardWidth() {
    return this->width();
}

void Board::paintEvent(QPaintEvent *ev) {
    QPainter painter(this);
    QPen pen("white");
    pen.setWidth(2);
    painter.setPen(pen);

    int rows = getBoardHeight() / CELLSIZE;
    int cols = getBoardWidth() / CELLSIZE;

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            painter.drawRect(j * CELLSIZE, i * CELLSIZE, CELLSIZE, CELLSIZE);
        }
    }
}

void Board::mousePressEvent(QMouseEvent* ev) {
    const QPoint p = ev->pos();
    int x = p.x() / CELLSIZE;
    int y = p.y() / CELLSIZE;
    std::cout << x << " " << y << std::endl;
}

