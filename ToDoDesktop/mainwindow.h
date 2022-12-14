#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "maincontroller.h"
#include "todolistview.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addBtn_clicked();

private:
    Ui::MainWindow *ui;
    ToDoC::MainController *mainController;
    TodoListView *todoListView;

};
#endif // MAINWINDOW_H
