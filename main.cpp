#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>

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
    

    window.resize(250, 150);
    window.setWindowTitle("Pathfinding Visualizer");
    window.show();

    return app.exec();
}
