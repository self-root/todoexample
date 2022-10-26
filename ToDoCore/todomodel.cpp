#include "todomodel.h"

#include "databaseaccess.h"
#include <QBrush>

namespace ToDoC {

ToDoModel::ToDoModel(QObject *parent)
    : QAbstractListModel(parent)
{
    dbAccess = DatabaseAccess::dbAccessInstance();
    todoList = dbAccess->mTodoDao->getTodoList();
}

int ToDoModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    Q_UNUSED(parent);
    return todoList->size();

}

QVariant ToDoModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    ToDo &todo = *todoList->at(index.row());
    switch (role) {
    case Qt::DisplayRole:
        return todo.todo();
    case Qt::BackgroundRole:
        switch (todo.necessity()) {
        case Level::Normal:
            return QBrush(QColor(0x87, 0xc3, 0x8f)); //"#87c38f"
        case Level::Important:
            return QBrush(QColor(0, 0x77, 0xb6)); //"#0077b6"
        default:
            return QBrush(QColor(0xcb, 0xf3, 0xf0)); //"#cbf3f0"
        }
    default:
        return QVariant();
    }

    return QVariant();
}

bool ToDoModel::addTodo(const ToDo &todo_)
{
    beginInsertRows(QModelIndex(), todoList->size(), todoList->size());
    if (dbAccess->mTodoDao->addToDo(todo_))
    {
        todoList->push_back(std::unique_ptr<ToDo>(new ToDo{todo_.id(), todo_.todo(), todo_.necessity()}));
        endInsertRows();
        return true;
    }
    return false;
}

bool ToDoModel::removeToDo(int row)
{
    beginRemoveRows(QModelIndex(), row, row);
    ToDo &todo = *todoList->at(row);
    if (dbAccess->mTodoDao->removeToDo(todo.id()))
    {
        todoList->erase(todoList->cbegin() + row);
        endRemoveRows();
        return true;
    }
    return false;
}

} // namespace ToDoc
