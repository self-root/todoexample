#include "catch2/catch_amalgamated.hpp"
#include "databaseaccess.h"
#include "tododao.h"
#include "todomodel.h"
#include <QSqlDatabase>
#include <QDebug>

TEST_CASE("My first test with Catch2", "[fancy]")
{
    REQUIRE(0 == 0);
}

TEST_CASE("Instance of database access", "[Instance]")
{
    ToDoC::DatabaseAccess *instance = ToDoC::DatabaseAccess::instance_;

    REQUIRE(instance == nullptr);

}

TEST_CASE("Todo DAO", "[TodoDao]")
{
    ToDoC::DatabaseAccess *dbAccess = ToDoC::DatabaseAccess::dbAccessInstance();
    REQUIRE(dbAccess->mTodoDao->database().tables().contains("todot"));
    dbAccess->deleteLater();
}

TEST_CASE("ToDo dao text", "[ToDoDao]")
{
    ToDoC::DatabaseAccess *dbAccess = ToDoC::DatabaseAccess::dbAccessInstance();
    auto tb = dbAccess->mTodoDao->getTodoList();
    int size = tb->size();
    QString todoId = ToDoC::ToDo::makeId();
    dbAccess->mTodoDao->addToDo(ToDoC::ToDo(todoId, QString("Debug procject B")));
    auto td2 = dbAccess->mTodoDao->getTodoList();
    REQUIRE((int)td2->size() == (size+1));
    auto &last = *td2->at(size);
    REQUIRE(last.id().toStdString() == todoId.toStdString());
    REQUIRE(last.todo().toStdString() == QString("Debug procject B").toStdString());

    dbAccess->mTodoDao->removeToDo(todoId);
    REQUIRE((int)dbAccess->mTodoDao->getTodoList()->size() == size);
}

TEST_CASE("ToDo model test", "[ToDoModel]")
{
    ToDoC::ToDoModel model;
    int modelSize = model.rowCount();
    ToDoC::DatabaseAccess *dbAccess = ToDoC::DatabaseAccess::dbAccessInstance();
    auto tb = dbAccess->mTodoDao->getTodoList();
    int tdSize = tb->size();
    REQUIRE(modelSize == tdSize);
    model.addTodo(ToDoC::ToDo(ToDoC::ToDo::makeId(), "Learn Python"));
    REQUIRE(model.rowCount() == (modelSize+1));
}
