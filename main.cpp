#include <QtWidgets>
#include "TaskWidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QWidget wgt;
//    TaskWidget* wgt1 = new TaskWidget;
//    TaskWidget* wgt2 = new TaskWidget;

//    QVBoxLayout* layout = new QVBoxLayout;
//    layout->addWidget(wgt1);
//    layout->addWidget(wgt2);
//    wgt.setLayout(layout);

//    wgt.show();
    TaskWidget wgt;
    wgt.show();

    return a.exec();
}
