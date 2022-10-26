#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    mainController = new ToDoC::MainController;

    todoListView = new TodoListView(mainController);
    ui->setupUi(this);

    ui->mainLayout->addWidget(todoListView);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addBtn_clicked()
{
    if (!ui->todoEdit->text().isEmpty())
    {
        mainController->model()->addTodo(ToDoC::ToDo(
             ToDoC::ToDo::makeId(),
             ui->todoEdit->text(),
             ToDoC::ToDo::intToLevel(ui->necessityChoice->currentIndex()))
         );
        ui->todoEdit->clear();
    }
}

