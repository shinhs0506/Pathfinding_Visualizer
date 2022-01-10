#include <QMainWindow>
#include <QApplication>
#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QCheckBox>
#include <QGridLayout>
#include <QObject>
#include <QMessageBox>

#include "Board.h"
#include "Algorithms/AlgorithmFactory.h"
#include "Analytics.h"

class PathfindingVisualizerApplication : public QMainWindow {

    private:
        Q_OBJECT
        const int WIDTH = 1000;
        const int HEIGHT = 600;
        Board* board;
        AlgorithmFactory *algoFactory;
        QStringList algoList;
        Algorithms *algo;

        const bool defaultAnalyticsToggleState = true;
        QCheckBox* checkBox;
        QComboBox* algorithmSelector;
        QPushButton* startButton;
        QPushButton* clearButton;
        QPushButton* resetButton;
        QPushButton* undoButton;

        void disableButtons();
        void enableButtons();

    private slots:
        void handleStartClick();
        void handleClearClick();
        void handleResetClick();
        void handleUndoClick();
        void itemChanged(QString str);

    public:
        PathfindingVisualizerApplication();
        void launch();
};
