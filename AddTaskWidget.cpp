#include "AddTaskWidget.h"

AddTaskWidget::AddTaskWidget(QWidget* parent) : QLabel(parent)
{
    m_task = new QLineEdit;
    m_addBtn = new QPushButton("Add");

    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(m_task);
    layout->setSpacing(5);
    layout->addWidget(m_addBtn);
    setLayout(layout);

    setMinimumSize(200, 50);
    m_addBtn->setMinimumSize(30, 30);

    connect(m_addBtn, SIGNAL(clicked()), SLOT(slotAddTask()));

    QFile styleFile(":/Style/AddTaskStyle.qss");
    styleFile.open(QFile::ReadOnly);
    QString style = QLatin1String(styleFile.readAll());
    styleFile.close();
    setStyleSheet(style);
}

void AddTaskWidget::slotAddTask()
{
    QString task = m_task->text();
    if(task.remove(' ') != "")
    {
        m_task->setText("");
        emit addTask(task);
    }
}
