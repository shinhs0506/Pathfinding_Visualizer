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
            if (this->grid.isStart(i, j)) {
                color = Qt::green;
            } else if (this->grid.isFinish(i, j)) {
                color = Qt::red;
            } else if (this->grid.isWall(i, j)) {
                color = Qt::black;
            } else if (this->grid.isExplored(i, j)) {
                color = Qt::blue;
            } else if (this->grid.isShortestPath(i, j)) {
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
        if (this->grid.isStart(row, col)) {
            isStartGrabbed = true;
            grabStart.first = row;
            grabStart.second = col;
        } else if (this->grid.isFinish(row, col)) {
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
		if (!this->grid.isStart(row, col) && !this->grid.isFinish(row, col)) {
            this->grid.setWall(row, col);
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
        
        if (isStartGrabbed && !this->grid.isFinish(row, col) && !this->grid.isWall(row, col)) {
            this->grid.setStart(row, col);
        } else if (isFinishGrabbed && !this->grid.isStart(row, col) && !this->grid.isWall(row, col)) {
            this->grid.setFinish(row, col);
        }
        isStartGrabbed = false;
        isFinishGrabbed = false;
    }
    this->update();
}

void Board::initialize() {
    rows = getBoardHeight() / CELLSIZE;
    cols = getBoardWidth() / CELLSIZE;
    this->grid.resize(rows, cols);
    // TODO: come up with a better way to initialize these values
    this->grid.resetStart();
    this->grid.resetFinish();
}

Grid Board::getGrid() {
    return this->grid;
}

void Board::drawPath(Path path) {
    for (std::pair<int, int> v : path.visited) {
        QTime dieTime = QTime::currentTime().addMSecs(2);
        while (QTime::currentTime() < dieTime) {
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        }
        this->grid.setExplored(v.first, v.second);
        this->update();
    }
    for (std::pair<int, int> v : path.shortest) {
        QTime dieTime = QTime::currentTime().addMSecs(2);
        while (QTime::currentTime() < dieTime) {
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        }
        this->grid.setShortestPath(v.first, v.second);
        this->update();
    }
}

void Board::clear() {
    this->grid.clear();
    this->update();
}

void Board::reset() {
    this->grid.reset();
    this->update();
}
