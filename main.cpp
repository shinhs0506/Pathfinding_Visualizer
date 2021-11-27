#include <QApplication>

#include "PathfindingVisualizerApplication.h"

int main(int argc, char *argv[]){

    QApplication app(argc, argv);

    PathfindingVisualizerApplication visualizer;
    visualizer.launch();

    return app.exec();
}

