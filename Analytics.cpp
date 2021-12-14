#include "Analytics.h"

Analytics::Analytics(QWidget *widget) {
    messageBox = new QMessageBox(widget);
}

void Analytics::show(Path path) {
    std::string msg = "explored " + std::to_string(path.getVisitedPathSize()) + " cells, ";

    int shortestLength = path.getShortestPathSize();
    if (!shortestLength) {
        msg += "could not reach the destination cell";
    } else {
        msg += "the shortest path has length of " + std::to_string(shortestLength);
    }

    messageBox->setText(QString::fromStdString(msg));
    messageBox->exec();
}
