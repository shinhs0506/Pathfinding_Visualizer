#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QObject>

#include "Board.h"
#include "Algorithms/Algorithms.h"
#include "Algorithms/BFS.cpp"

#include <iostream>

const int WIDTH = 1000;
const int HEIGHT = 600;

Board *b;

void handleStartClick() {
    cout << "solving" << endl;
    Algorithms* algo = new BFS();
    Path path = algo->solve(b->getGrid(), b->getStart(), b->getFinish());
    b->drawPath(path);
    cout << path.shortest[path.shortest.size() - 1].first << " " << path.shortest[path.shortest.size() - 1].second << endl;
}

int main(int argc, char *argv[]){

    QApplication app(argc, argv);

    QWidget* window = new QWidget();
    QGridLayout *layout = new QGridLayout(window);

    window->setLayout(layout);
    window->setFixedSize(WIDTH, HEIGHT);
    window->setWindowFlags(Qt::Widget | Qt::MSWindowsFixedSizeDialogHint);
    window->setWindowTitle("Pathfinding Visualizer");

    QPushButton *startButton = new QPushButton("start");
    QPushButton *clearButton = new QPushButton("clear");
    QPushButton *resetButton = new QPushButton("reset");
    layout->addWidget(startButton, 0, 0);
    layout->addWidget(clearButton, 0, 1);
    layout->addWidget(resetButton, 0, 2);

    Board *board = new Board();
    b = board;
    layout->addWidget(board, 1, 0, -1, -1);

    QObject::connect(startButton, &QPushButton::clicked, &handleStartClick);

    window->show();
    board->initialize();

    return app.exec();
}

