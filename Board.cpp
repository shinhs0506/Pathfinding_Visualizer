#include<QWidget>
#include<QRect>
#include<QPainter>
#include<QColor>

const int CELLSIZE = 20;

class Board : public QWidget {
    
    private:
        int getBoardWidth();
        int getBoardHeight();

    protected:
        void paintEvent(QPaintEvent *event) override;

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

void Board::paintEvent(QPaintEvent *e) {
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

