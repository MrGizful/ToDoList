#include "TaskListWidget.h"

TaskListWidget::TaskListWidget(QList<TaskWidget*> list, QWidget *parent) : QWidget(parent), m_taskList(list)
{
    QVBoxLayout* layout = new QVBoxLayout;
    layout->setSpacing(3);
    for(int i = 0; i < m_taskList.size(); i++)
    {
        layout->addWidget(m_taskList.at(i));
        connect(m_taskList.at(i), SIGNAL(deleteTask(QWidget*)), SLOT(slotDeleteTask(QWidget*)));
    }
    setLayout(layout);

    QFile styleFile(":/Style/ActiveTaskStyle.qss");
    styleFile.open(QFile::ReadOnly);
    QString style = QLatin1String(styleFile.readAll());
    styleFile.close();
    setStyleSheet(style);
}

void TaskListWidget::slotDeleteTask(QWidget* task)
{
    if(task)
        for(int i = 0; i < m_taskList.size(); i++)
            if(m_taskList.at(i) == task)
            {
                m_taskList.remove(i);
                layout()->removeWidget(task);
                delete task;
                break;
            }
}

void TaskListWidget::slotAddTask(const QString& taskName)
{
    TaskWidget* wgt = new TaskWidget(taskName);
    connect(wgt, SIGNAL(deleteTask(QWidget*)), SLOT(slotDeleteTask));
    m_taskList.append(wgt);
    layout()->addWidget(wgt);
}
