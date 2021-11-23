#include <QTime>
#include <QCoreApplication>
#include <QEventLoop>


#include "Board.h"

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

void Board::paintEvent(QPaintEvent *) {
    QPainter painter(this);

    QPen pen("white");
    pen.setWidth(2);
    painter.setPen(pen);

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            painter.drawRect(j * CELLSIZE, i * CELLSIZE, CELLSIZE, CELLSIZE);
    
            QColor color;
            // TODO: better checking mechanism 
            if (start.first == i && start.second == j) {
                color = Qt::green;
            } else if (finish.first == i && finish.second == j) {
                color = Qt::red;
            } else if (grid[i][j] == WALL) {
                color = Qt::black;
            } else if (grid[i][j] == EXPLORED) {
                color = Qt::blue;
            } else if (grid[i][j] == SHORTESTPATH) {
                color = Qt::darkBlue;
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
        if (start.first == row && start.second == col) {
            isStartGrabbed = true;
            grabStart.first = row;
            grabStart.second = col;
        } else if (finish.first == row && finish.second == col) {
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
		if (start.first != row && start.second != col && finish.first != row && finish.second != col) {
			grid[row][col] = WALL;
		}
    }
	this->update();
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
        
        if (isStartGrabbed && finish.first != row && finish.second != row && grid[row][col] != WALL) {
            start.first = row;
            start.second = col;
        } else if (isFinishGrabbed && start.first != row && start.second != col && grid[row][col] != WALL) {
            finish.first = row;
            finish.second = col;
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
    // TODO: come up with a better way to initialize these values
    start.first = 1;
    start.second = 1;
    finish.first = 1;
    finish.second = 10;
}

vector<vector<int>> Board::getGrid() 
{
    return grid;
}

pair<int, int> Board::getStart() 
{
    return start;
}

pair<int, int> Board::getFinish() 
{
    return finish;
}

void Board::drawPath(Path path) {
    for (std::pair<int, int> v : path.visited) {
        QTime dieTime = QTime::currentTime().addMSecs(2);
        while (QTime::currentTime() < dieTime) {
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        }
        grid[v.first][v.second] = EXPLORED;
        this->update();
    }
    for (std::pair<int, int> v : path.shortest) {
        QTime dieTime = QTime::currentTime().addMSecs(2);
        while (QTime::currentTime() < dieTime) {
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        }
        grid[v.first][v.second] = SHORTESTPATH;
        this->update();
    }
}
