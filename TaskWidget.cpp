#include "TaskWidget.h"

TaskWidget::TaskWidget(QString task, QWidget *parent) : QWidget(parent)
{
    m_completion = new QCheckBox;
    m_task = new QLineEdit(task);
    m_deleteBtn = new QPushButton("X");
    m_deleteBtn->setFixedWidth(25);

    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(m_completion);
    layout->setSpacing(5);
    layout->addWidget(m_task);
    layout->addWidget(m_deleteBtn);
    setLayout(layout);

    connect(m_completion, SIGNAL(stateChanged(int)), SLOT(slotChangeState(int)));
    connect(m_deleteBtn, SIGNAL(clicked()), SLOT(slotDeleteTask()));

    QFile styleFile(":/Style/ActiveTaskStyle.qss");
    styleFile.open(QFile::ReadOnly);
    activeTaskStyleSheet = QLatin1String(styleFile.readAll());
    styleFile.close();

    styleFile.setFileName(":/Style/CompletedTaskStyle.qss");
    styleFile.open(QFile::ReadOnly);
    completedTaskStyleSheet = QLatin1String(styleFile.readAll());
    styleFile.close();

    setStyleSheet(activeTaskStyleSheet);
}

void TaskWidget::slotChangeState(int state)
{
    if(state)
        setStyleSheet(completedTaskStyleSheet);
    else
        setStyleSheet(activeTaskStyleSheet);
}

void TaskWidget::slotDeleteTask()
{
    emit deleteTask(this);
}
