#include "todo.h"
#include <QDateTime>

namespace ToDoC {
ToDo::ToDo(QObject *parent)
    : QObject{parent}
{

}

ToDo::ToDo(const QString &id, const QString &todo, Level necessity)
    : mId(id), mToDo(todo), mNecessity(necessity)
{
}

const QString &ToDo::id() const
{
    qDebug() << "Getting ID: " << mId;
    return mId;
}

void ToDo::setId(const QString &newId)
{
    mId = newId;
}

void ToDo::setToDo(const QString &newToDo)
{
    mToDo = newToDo;
}

const QString &ToDo::todo() const
{
    return mToDo;
}

QString ToDo::makeId()
{
    return QDateTime::currentDateTime().toString("ddMMyyhhmmsszzz");
}

Level ToDo::intToLevel(int i)
{
    switch (i) {
    case 1:
        return Level::Normal;
    case 2:
        return Level::Important;
    default:
        return Level::Optional;
    }
}

int ToDo::levelToInt(Level l)
{
    switch (l) {
    case Level::Normal:
        return 1;
    case Level::Important:
        return 2;
    default:
        return 0;
    }
}

Level ToDo::necessity() const
{
    return mNecessity;
}

void ToDo::setNecessity(Level newNecessity)
{
    mNecessity = newNecessity;
}

}

