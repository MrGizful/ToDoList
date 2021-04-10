#pragma once
#include "TaskListWidget.h"
#include "AddTaskWidget.h"

class ToDoListWidget : public QLabel
{
    Q_OBJECT
private:
    TaskListWidget* m_taskListWgt;
    AddTaskWidget* m_addTaskWgt;

public:
    ToDoListWidget(QWidget* parent = nullptr);
};
