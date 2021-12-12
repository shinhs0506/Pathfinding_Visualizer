#include "Analytics.h"

Analytics::Analytics(QWidget *widget) {
    messageBox = new QMessageBox(widget);
}

void Analytics::show(Path path) {
    std::string msg = "explored " + std::to_string(path.visited.size()) + " cells, ";

    int shortestLength = path.shortest.size();
    if (!shortestLength) {
        msg += "could not reach the destination cell";
    } else {
        msg += "the shortest path has length of " + std::to_string(path.shortest.size());
    }

    messageBox->setText(QString::fromStdString(msg));
    messageBox->exec();
}
