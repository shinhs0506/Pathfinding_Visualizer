#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QRect>

#include "Board.cpp"

const int WIDTH = 250;
const int HEIGHT = 150;

int main(int argc, char *argv[]){

    QApplication app(argc, argv);

    QWidget window;
    QPushButton *startButton = new QPushButton("start");
    QPushButton *clearButton = new QPushButton("clear");
    QPushButton *resetButton = new QPushButton("reset");

    QGridLayout *layout = new QGridLayout(&window);

    layout->addWidget(startButton, 0, 0);
    layout->addWidget(clearButton, 0, 1);
    layout->addWidget(resetButton, 0, 2);
    
    Board *board = new Board();
    layout->addWidget(board, 1, 0, -1, -1);

    window.resize(WIDTH, HEIGHT);
    window.setWindowTitle("Pathfinding Visualizer");
    window.show();

    return app.exec();
}
