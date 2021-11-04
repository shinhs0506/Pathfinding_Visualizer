#include<QWidget>
#include<QRect>
#include<QPainter>
#include<QColor>

#include<iostream>
using namespace std;

class Board : public QWidget {
    
    public:
        Board();

    protected:
        void paintEvent(QPaintEvent *event) override;

    private:
        int boardWidth;
        int boardHeight;
};

Board::Board() {
    boardWidth = this->width();
    boardHeight = this->height(); 
}

void Board::paintEvent(QPaintEvent *e) {
    QRect rect(0, 0, boardWidth, boardHeight);
    QPainter painter(this);
    painter.fillRect(rect, QColor("white"));
}
