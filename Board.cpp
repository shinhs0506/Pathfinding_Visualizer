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
const int EMPTY = 0;
const int START = 1;
const int FINISH = 2;
const int WALL = 3;

class Board : public QWidget {
    
    private:
        bool isMousePressed;
        int rows;
        int cols;
        vector<vector<int>> grid;
        bool isStartGrabbed;
        bool isFinishGrabbed;
        pair<int, int> grabStart;

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
    isStartGrabbed = false;
    isFinishGrabbed = false;
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
        int col = p.x() / CELLSIZE;
        int row = p.y() / CELLSIZE;
        if (grid[row][col] == START) {
            isStartGrabbed = true;
            grabStart.first = row;
            grabStart.second = col;
        } else if (grid[row][col] == FINISH) {
            isFinishGrabbed = true;
            grabStart.first = row;
            grabStart.second = col;
        }
    } else if (ev->button() == Qt::RightButton) {
    }
}

void Board::mouseMoveEvent(QMouseEvent* ev) {
    if (!isMousePressed) return;
    
    if (ev->buttons() & Qt::LeftButton) {
    } else if (ev->buttons() & Qt::RightButton) {
        const QPoint p = ev->pos();
        int col = p.x() / CELLSIZE;
        int row = p.y() / CELLSIZE;
    }

}

void Board::mouseReleaseEvent(QMouseEvent* ev) {
    isMousePressed = false;
    if (!this->rect().contains(ev->pos())) {
        return;
    }
    if (ev->button() == Qt::LeftButton) {
        const QPoint p = ev->pos();
        int col = p.x() / CELLSIZE;
        int row = p.y() / CELLSIZE;
        cout << grabStart.first << " " << grabStart.second << endl;
        cout << grid[grabStart.first][grabStart.second] << endl;
        cout << row << " " << col << endl;
        cout << grid[row][col] << endl;
        
        if (isStartGrabbed && grid[row][col] != FINISH) {
            grid[grabStart.first][grabStart.second] = EMPTY;
            grid[row][col] = START;
        } else if (isFinishGrabbed && grid[row][col] != START) {
            grid[grabStart.first][grabStart.second] = EMPTY;
            grid[row][col] = FINISH;
        }
        isStartGrabbed = false;
        isFinishGrabbed = false;
    }
    this->update();
}

void Board::initialize() {
    rows = getBoardHeight() / CELLSIZE;
    cols = getBoardWidth() / CELLSIZE;
    grid.resize(rows);
    for (vector<int>& row : grid) {
        row.resize(cols);
    }
    grid[1][1] = START;
    grid[1][10] = FINISH;
}
