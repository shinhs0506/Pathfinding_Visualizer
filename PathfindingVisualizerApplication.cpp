#include "PathfindingVisualizerApplication.h"

void PathfindingVisualizerApplication::disableButtons() {
    checkBox->setEnabled(false);    
    algorithmSelector->setEnabled(false);    
    startButton->setEnabled(false);    
    clearButton->setEnabled(false);    
    resetButton->setEnabled(false);    
}

void PathfindingVisualizerApplication::enableButtons() {
    checkBox->setEnabled(true);    
    algorithmSelector->setEnabled(true);    
    startButton->setEnabled(true);    
    clearButton->setEnabled(true);    
    resetButton->setEnabled(true);    
}

PathfindingVisualizerApplication::PathfindingVisualizerApplication() {
    QString algorithms = "BFS,DFS,Random,AStar";
    algoList = algorithms.split(",");
    algo = algoFactory->switchAlgo(algoList[0]);
}

void PathfindingVisualizerApplication::handleStartClick() {
    disableButtons();
    cout << "solving" << endl;

    Path path = algo->solve(board->getGrid());
    board->drawPath(path);

    if (checkBox->isChecked()) {
        Analytics *analytics = new Analytics(this);
        analytics->show(path);
    }

    enableButtons();
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
    setCentralWidget(window);
    window->setFixedSize(WIDTH, HEIGHT);
    window->setWindowFlags(Qt::Widget | Qt::MSWindowsFixedSizeDialogHint);
    window->setWindowTitle("Pathfinding Visualizer");

    algorithmSelector = new QComboBox(window);
    algorithmSelector->addItems(algoList);
    connect(algorithmSelector, SIGNAL(currentTextChanged(QString)), this, SLOT(itemChanged(QString)));
    layout->addWidget(algorithmSelector, 0, 0);

    startButton = new QPushButton("start");
    clearButton = new QPushButton("clear");
    resetButton = new QPushButton("reset");
    QObject::connect(startButton, &QPushButton::clicked, this, &PathfindingVisualizerApplication::handleStartClick);
    QObject::connect(clearButton, &QPushButton::clicked, this, &PathfindingVisualizerApplication::handleClearClick);
    QObject::connect(resetButton, &QPushButton::clicked, this, &PathfindingVisualizerApplication::handleResetClick);
    layout->addWidget(startButton, 0, 1);
    layout->addWidget(clearButton, 0, 2);
    layout->addWidget(resetButton, 0, 3);

    checkBox = new QCheckBox("Show Analytics", this);
    checkBox->setChecked(defaultAnalyticsToggleState);
    layout->addWidget(checkBox, 1, 3);

    board = new Board();
    layout->addWidget(board, 2, 0, -1, -1);

    show();
    board->initialize();
}

