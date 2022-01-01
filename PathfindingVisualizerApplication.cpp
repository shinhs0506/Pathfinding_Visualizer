#include "PathfindingVisualizerApplication.h"

PathfindingVisualizerApplication::PathfindingVisualizerApplication() {
    QString algorithms = "BFS,DFS,Random,AStar";
    algoList = algorithms.split(",");
    algo = algoFactory->switchAlgo(algoList[0]);
}

void PathfindingVisualizerApplication::handleStartClick() {
    cout << "solving" << endl;
    Path path = algo->solve(board->getGrid());
    board->drawPath(path);

    Analytics *analytics = new Analytics(this);
    analytics->show(path);
    

    //cout << path.shortest[path.shortest.size() - 1].first << " " << path.shortest[path.shortest.size() - 1].second << endl;
}

void PathfindingVisualizerApplication::handleClearClick() {
    board->clear();
}

void PathfindingVisualizerApplication::handleResetClick() {
    board->reset();
}

void PathfindingVisualizerApplication::itemChanged(QString str) {
    algo = algoFactory->switchAlgo(str);
}

void PathfindingVisualizerApplication::launch() {

    QWidget* window = new QWidget();
    QGridLayout *layout = new QGridLayout(window);

    window->setLayout(layout);
    window->setFixedSize(WIDTH, HEIGHT);
    window->setWindowFlags(Qt::Widget | Qt::MSWindowsFixedSizeDialogHint);
    window->setWindowTitle("Pathfinding Visualizer");

    QComboBox *algorithmSelector = new QComboBox(window);
    algorithmSelector->addItems(algoList);
    connect(algorithmSelector, SIGNAL(currentTextChanged(QString)), this, SLOT(itemChanged(QString)));
    layout->addWidget(algorithmSelector, 0, 0);

    QPushButton *startButton = new QPushButton("start");
    QPushButton *clearButton = new QPushButton("clear");
    QPushButton *resetButton = new QPushButton("reset");
    QObject::connect(startButton, &QPushButton::clicked, this, &PathfindingVisualizerApplication::handleStartClick);
    QObject::connect(clearButton, &QPushButton::clicked, this, &PathfindingVisualizerApplication::handleClearClick);
    QObject::connect(resetButton, &QPushButton::clicked, this, &PathfindingVisualizerApplication::handleResetClick);
    layout->addWidget(startButton, 0, 1);
    layout->addWidget(clearButton, 0, 2);
    layout->addWidget(resetButton, 0, 3);

    board = new Board();
    layout->addWidget(board, 1, 0, -1, -1);


    window->show();
    board->initialize();
}

