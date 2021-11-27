#include <QMainWindow>
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QObject>

#include "Board.h"
#include "Algorithms/BFS.h"

class PathfindingVisualizerApplication : public QMainWindow {

    private:
        const int WIDTH = 1000;
        const int HEIGHT = 600;
        Board* board;

    private slots:
        void handleStartClick();
        void handleClearClick();
        void handleResetClick();


    public:
        PathfindingVisualizerApplication();
        void launch();
};
