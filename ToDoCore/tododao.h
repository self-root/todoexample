#ifndef TODOC_TODODAO_H
#define TODOC_TODODAO_H

#include "ToDoCore_global.h"
#include <QObject>
#include <memory>
#include <vector>

#include "todo.h"

class QSqlDatabase;
namespace ToDoC {

class TODOCORE_EXPORT ToDoDao : public QObject
{
    Q_OBJECT
public:
    explicit ToDoDao(QSqlDatabase &database,QObject *parent = nullptr);
    const QSqlDatabase &database() const;
    std::unique_ptr<std::vector<std::unique_ptr<ToDo>>> getTodoList() const;
    bool addToDo(const ToDo &todo) const;
    bool removeToDo(const QString &todoId) const;
private:
    QSqlDatabase &mDatabase;

    void init() const;

};

} // namespace ToDoC

#endif // TODOC_TODODAO_H
