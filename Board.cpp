#include <QTime>
#include <QCoreApplication>
#include <QEventLoop>


#include "Board.h"

Board::Board() {
    isMousePressed = false;
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
            if (this->grid->isStart(i, j)) {
                color = Qt::green;
            } else if (this->grid->isFinish(i, j)) {
                color = Qt::red;
            } else if (this->grid->isWall(i, j)) {
                color = Qt::black;
            } else if (this->grid->isExplored(i, j)) {
                color = Qt::blue;
            } else if (this->grid->isShortestPath(i, j)) {
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

    const QPoint p = ev->pos();
    int col = p.x() / CELLSIZE;
    int row = p.y() / CELLSIZE;

    std::pair<int, int> point = std::make_pair(row, col);
    if (ev->button() == Qt::LeftButton) {
        start = point;
    } else if (ev->button() == Qt::RightButton) {
        walls.push_back(point);    
    }
}

void Board::mouseMoveEvent(QMouseEvent* ev) {
    if (!isMousePressed) return;

    if (!this->rect().contains(ev->pos())) {
        return;
    }

    const QPoint p = ev->pos();
    int col = p.x() / CELLSIZE;
    int row = p.y() / CELLSIZE;

    if (ev->buttons() & Qt::LeftButton) {

    } else if (ev->buttons() & Qt::RightButton) {
		if (!this->grid->isStart(row, col) && !this->grid->isFinish(row, col)) {
            walls.push_back(std::make_pair(row, col));
		}
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
        
        finish = std::make_pair(row, col);
        movePointCommand = new MovePointCommand(grid, this->start, this->finish);
        movePointCommand->execute();
        commandHistory->push(movePointCommand); 
    } else if (ev->button() == Qt::RightButton) {
        createWallCommand = new CreateWallCommand(grid, this->walls);
        createWallCommand->execute();
        commandHistory->push(createWallCommand); 
        this->walls.clear();
    }
    this->update();
}

void Board::initialize() {
    rows = getBoardHeight() / CELLSIZE;
    cols = getBoardWidth() / CELLSIZE;
    this->grid->resize(rows, cols);
    // TODO: come up with a better way to initialize these values
    this->grid->resetStart();
    this->grid->resetFinish();
}

Grid* Board::getGrid() {
    return this->grid;
}

void Board::drawPath(Path path) {
    for (std::pair<int, int>& v : path.getVisitedPath()) {
        QTime dieTime = QTime::currentTime().addMSecs(2);
        while (QTime::currentTime() < dieTime) {
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        }
        this->grid->setExplored(v.first, v.second);
        this->update();
    }
    for (std::pair<int, int>& v : path.getShortestPath()) {
        QTime dieTime = QTime::currentTime().addMSecs(2);
        while (QTime::currentTime() < dieTime) {
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        }
        this->grid->setShortestPath(v.first, v.second);
        this->update();
    }
}

void Board::clear() {
    this->grid->clear();
    this->update();
}

void Board::reset() {
    this->grid->reset();
    this->update();
}

void Board::undo() {
    this->commandHistory->pop();
}

void Board::clearHistory() {
    this->commandHistory->reset();
}
