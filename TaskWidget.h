#pragma once
#include <QtWidgets>

class TaskWidget : public QLabel
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
    QString getActiveTaskStyle();
    QString getCompletedTaskStyle();

signals:
    void deleteTask(QWidget*);

public slots:
    void slotChangeState(int);
    void slotDeleteTask();

};
