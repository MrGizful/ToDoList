#include <QtWidgets>
#include "TaskWidget.h"
#include "TaskListWidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QList<TaskWidget*> list;
    list.append(new TaskWidget("Task 1"));
    list.append(new TaskWidget("Task 2"));
    list.append(new TaskWidget("Task 3"));
    list.append(new TaskWidget("Task 4"));

    TaskListWidget wgt(list);
    wgt.show();

    return a.exec();
}
