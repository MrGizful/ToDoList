#pragma once
#include <QtWidgets>

class TaskWidget : public QWidget
{
    Q_OBJECT
private:
    QCheckBox* m_completion;
    QLineEdit* m_task;
    QPushButton* m_deleteBtn;

    QString activeTaskStyleSheet;
    QString completedTaskStyleSheet;

public:
    TaskWidget(QString task = "To do", QWidget *parent = nullptr);

signals:
    void deleteTask(QWidget*);

public slots:
    void slotChangeState(int);
    void slotDeleteTask();

};
