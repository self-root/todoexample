#ifndef TODOC_TODOMODEL_H
#define TODOC_TODOMODEL_H

#include <QAbstractListModel>
#include "todo.h"

namespace ToDoC {
class DatabaseAccess;

class ToDoModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit ToDoModel(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool addTodo(const ToDo &todo_);

    bool removeToDo(int row);
private:
    DatabaseAccess *dbAccess;
    std::unique_ptr<std::vector<std::unique_ptr<ToDo>>> todoList;
};

} // namespace ToDoc

#endif // TODOC_TODOMODEL_H
