#ifndef BOARD_H
#define BOARD_H

#include <vector>

#include <QWidget>
#include <QRect>
#include <QPainter>
#include <QColor>
#include <QMouseEvent>
#include <QPoint>

#include "Grid.h"
#include "Algorithms/Path.h"

#include <iostream>
using namespace std;

const int CELLSIZE = 20;

class Board : public QWidget {
    
    private:
        bool isMousePressed;
        int rows;
        int cols;
        //vector<vector<int>> grid;
        //pair<int, int> start;
        //pair<int, int> finish;
        Grid grid;
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
        Grid getGrid();
        //pair<int, int> getStart();
        //pair<int, int> getFinish();
        void drawPath(Path path);
        void clear();
};

#endif
