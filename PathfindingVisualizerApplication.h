#include <QMainWindow>
#include <QApplication>
#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QGridLayout>
#include <QObject>
#include <QMessageBox>

#include "Board.h"
#include "Algorithms/AlgorithmFactory.h"

class PathfindingVisualizerApplication : public QMainWindow {

    private:
        Q_OBJECT
        const int WIDTH = 1000;
        const int HEIGHT = 600;
        Board* board;
        AlgorithmFactory *algoFactory;
        QStringList algoList;
        Algorithms *algo;

    private slots:
        void handleStartClick();
        void handleClearClick();
        void handleResetClick();
        void itemChanged(QString str);

    public:
        PathfindingVisualizerApplication();
        void launch();
};
