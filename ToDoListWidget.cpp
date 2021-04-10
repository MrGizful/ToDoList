#include "ToDoListWidget.h"

ToDoListWidget::ToDoListWidget(QWidget* parent) : QLabel(parent)
{
    m_taskListWgt = new TaskListWidget(QList<TaskWidget*>());
    m_addTaskWgt = new AddTaskWidget;

    QFrame* frame = new QFrame;
    QHBoxLayout* frameLayout = new QHBoxLayout;
    frameLayout->addWidget(m_taskListWgt);
    frame->setLayout(frameLayout);
    frame->setMinimumSize(300, 300);


    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(frame, 3);
    layout->addWidget(m_addTaskWgt);
    setLayout(layout);

    connect(m_addTaskWgt, SIGNAL(addTask(const QString&)), m_taskListWgt, SLOT(slotAddTask(const QString&)));

    QFile styleFile(":/Style/ToDoListWidgetStyle.qss");
    styleFile.open(QFile::ReadOnly);
    QString style = QLatin1String(styleFile.readAll());
    styleFile.close();
    setStyleSheet(style);
    frame->setStyleSheet(style);
}
