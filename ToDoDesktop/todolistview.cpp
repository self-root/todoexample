#include "todolistview.h"
#include "maincontroller.h"

TodoListView::TodoListView(ToDoC::MainController *controller, QListView *parent)
    : QListView(parent), mainController(controller)
{
    setModel(mainController->model());
}

void TodoListView::mouseDoubleClickEvent(QMouseEvent *mouseEvent)
{
    QModelIndex modelIndex = this->indexAt(mouseEvent->pos());
    qDebug() << "Remove: " << this->model()->data(modelIndex);
    mainController->model()->removeToDo(modelIndex.row());
}
