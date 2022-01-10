#ifndef BOARD_H
#define BOARD_H

#include <vector>

#include <QWidget>
#include <QRect>
#include <QPainter>
#include <QColor>
#include <QMouseEvent>
#include <QPoint>

#include "Commands/Command.h"
#include "Grid.h"
#include "Path.h"
#include "Commands/CreateWallCommand.h"
#include "Commands/MovePointCommand.h"
#include "Commands/CommandHistory.h"

#include <iostream>
using namespace std;

const int CELLSIZE = 20;

class Board : public QWidget {
    
    private:
        bool isMousePressed;
        int rows;
        int cols;
        pair<int, int> start;
        pair<int, int> finish;
        std::vector<pair<int, int>> walls;
        Grid* grid = new Grid();
        Command *createWallCommand = NULL;
        Command *movePointCommand = NULL;
        CommandHistory *commandHistory = new CommandHistory();

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
        Grid* getGrid();
        //pair<int, int> getStart();
        //pair<int, int> getFinish();
        void drawPath(Path path);
        void clear();
        void reset();
        void undo();
        void clearHistory();
};

#endif
