#ifndef BOARD_H
#define BOARD_H

#include <vector>

#include <QWidget>
#include <QRect>
#include <QPainter>
#include <QColor>
#include <QMouseEvent>
#include <QPoint>

#include <iostream>
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

#endif
