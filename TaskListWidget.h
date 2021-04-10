#pragma once
#include <QtWidgets>
#include "TaskWidget.h"

class TaskListWidget : public QWidget
{
    Q_OBJECT
private:
    QList<TaskWidget*> m_taskList;

public:
    TaskListWidget(QList<TaskWidget*> list, QWidget *parent = nullptr);

public slots:
    void slotDeleteTask(TaskWidget* task);
    void slotAddTask(const QString& taskName);

};
