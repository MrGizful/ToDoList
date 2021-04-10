#pragma once
#include <QtWidgets>

class AddTaskWidget : public QLabel
{
    Q_OBJECT
private:
    QLineEdit* m_task;
    QPushButton* m_addBtn;

public:
    AddTaskWidget(QWidget* parent = nullptr);

signals:
    void addTask(const QString&);

public slots:
    void slotAddTask();
};
