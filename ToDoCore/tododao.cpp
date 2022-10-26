#include "tododao.h"
#include <QSqlQuery>
#include <QSqlResult>
#include <QSqlError>

namespace ToDoC {

ToDoDao::ToDoDao(QSqlDatabase &database, QObject *parent)
    : QObject{parent}, mDatabase(database)
{
    init();
}

const QSqlDatabase &ToDoDao::database() const
{
    return mDatabase;
}

std::unique_ptr<std::vector<std::unique_ptr<ToDo> > > ToDoDao::getTodoList() const
{
    QSqlQuery query("SELECT * FROM todot", mDatabase);
    query.exec();
    std::unique_ptr<std::vector<std::unique_ptr<ToDo> > > td(new std::vector<std::unique_ptr<ToDo>>);
    while (query.next())
    {

        ToDo *t = new ToDo{
            query.value("todoId").toString(),
            query.value("todo").toString(),
            ToDo::intToLevel(query.value("necessity").toInt())
    };
        td->push_back(std::unique_ptr<ToDo>(t));
    }

    return td;
}

bool ToDoDao::addToDo(const ToDo &todo) const
{
    QSqlQuery query(mDatabase);
    query.prepare("INSERT INTO todot(todoId, todo, necessity) VALUES (:todoId, :todo, :necessity)");
    query.bindValue(":todoId", todo.id());
    query.bindValue(":todo", todo.todo());
    query.bindValue(":necessity", ToDo::levelToInt(todo.necessity()));

    if (!query.exec())
    {
        qDebug() << "ERROR while inserting " << todo.id() << ":" << todo.todo() << ": " << query.lastError().text();
        return false;
    }
    return true;
}

bool ToDoDao::removeToDo(const QString &todoId) const
{
    QSqlQuery query(mDatabase);
    query.prepare("DELETE FROM todot WHERE todoId = :todoId");
    query.bindValue(":todoId", todoId);

    if (!query.exec())
    {
        qDebug() << "ERROR while removing " << todoId << ": " << query.lastError().text();
        return false;
    }
    return true;
}

void ToDoDao::init() const
{
    QSqlQuery query("CREATE TABLE IF NOT EXISTS todot (todoId TEXT UNIQUE, todo TEXT, necessity INTEGER NOT NULL, PRIMARY KEY(todoId))", mDatabase);

    if (!query.exec())
        qDebug() << "ERROR while creating table todot: " << query.lastError().text();
}

} // namespace ToDoC
