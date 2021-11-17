#include<vector>

#include<QWidget>
#include<QRect>
#include<QPainter>
#include<QColor>
#include<QMouseEvent>
#include<QPoint>

#include<iostream>
using namespace std;

const int CELLSIZE = 20;
const int START = 1;
const int FINISH = 2;
const int WALL = 3;

class Board : public QWidget {
    
    private:
        bool isMousePressed;
        int rows;
        int cols;
        vector<vector<int>> grid;

        int getBoardWidth();
        int getBoardHeight();

    protected:
        void paintEvent(QPaintEvent *ev) override;
        void mousePressEvent(QMouseEvent *ev) override;
        void mouseMoveEvent(QMouseEvent *ev) override;
        void mouseReleaseEvent(QMouseEvent *ev) override;

    public:
        Board();
        void initialize();
};

Board::Board() {
    isMousePressed = false;
}

int Board::getBoardHeight() {
    return this->height();
}

int Board::getBoardWidth() {
    return this->width();
}

void Board::paintEvent(QPaintEvent *ev) {
    cout << getBoardWidth() << endl;
    QPainter painter(this);
    QPen pen("white");
    pen.setWidth(2);
    painter.setPen(pen);

    cout << grid.size() << " " << grid[0].size() << endl;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            painter.drawRect(j * CELLSIZE, i * CELLSIZE, CELLSIZE, CELLSIZE);
    
            QColor color;
            if (grid[i][j] == START) {
                color = Qt::green;
            } else if (grid[i][j] == FINISH) {
                color = Qt::red;
            } else if (grid[i][j] == WALL) {
                color = Qt::black;
            } else {
                color = Qt::gray;
            }
            painter.fillRect(j * CELLSIZE, i * CELLSIZE, CELLSIZE, CELLSIZE, color);
        }
    }
}

void Board::mousePressEvent(QMouseEvent* ev) {
    isMousePressed = true;
    if (ev->button() == Qt::LeftButton) {
        const QPoint p = ev->pos();
        int x = p.x() / CELLSIZE;
        int y = p.y() / CELLSIZE;
        std::cout << "left clicked " << x << " " << y << std::endl;
    } else if (ev->button() == Qt::RightButton) {
        std::cout << "right clicked " << std::endl;
    }
}

void Board::mouseMoveEvent(QMouseEvent* ev) {
    std::cout << isMousePressed << std::endl;
    if (!isMousePressed) return;
    
    if (ev->buttons() & Qt::LeftButton) {
        std::cout << "left moved " << std::endl;
    } else if (ev->buttons() & Qt::RightButton) {
        const QPoint p = ev->pos();
        int x = p.x() / CELLSIZE;
        int y = p.y() / CELLSIZE;
        std::cout << "right moved " << x << " " << y << std::endl;
    }

}

void Board::mouseReleaseEvent(QMouseEvent* ev) {
    isMousePressed = false;
    if (ev->button() == Qt::LeftButton) {
        const QPoint p = ev->pos();
        int x = p.x() / CELLSIZE;
        int y = p.y() / CELLSIZE;
        std::cout << "left released " << x << " " << y << std::endl;
    } else if (ev->button() == Qt::RightButton) {
        std::cout << "right release " << std::endl;
    }
}

void Board::initialize() {
    cout<< getBoardWidth() << endl;
    rows = getBoardHeight() / CELLSIZE;
    cols = getBoardWidth() / CELLSIZE;
    grid.resize(rows);
    for (vector<int>& row : grid) {
        row.resize(cols);
    }
    grid[1][1] = START;
    grid[1][10] = FINISH;
    this->update();
}
