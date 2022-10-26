#include "databaseaccess.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

namespace ToDoC {

DatabaseAccess *DatabaseAccess::instance_ = nullptr;

DatabaseAccess::DatabaseAccess(QObject *parent)
    : QObject{parent}, mDatabase(new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE")))
{
    mDatabase->setDatabaseName("todo.db");
    if (!mDatabase->open())
        qDebug() << "Failed to open database: " << mDatabase->lastError().text();
    mTodoDao = new ToDoDao(*mDatabase);

}

DatabaseAccess *ToDoC::DatabaseAccess::dbAccessInstance()
{
    if(instance_ == nullptr)
        instance_ = new DatabaseAccess;
    return instance_;
}

} // namespace ToDo

