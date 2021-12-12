#include <QWidget>
#include <QMessageBox>

#include "Algorithms/Path.h"

class Analytics {
    private:
        QMessageBox *messageBox;

    public:
        Analytics(QWidget *widget);
        void show(Path path); 
};
