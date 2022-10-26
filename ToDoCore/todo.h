#ifndef TODO_H
#define TODO_H
#include "ToDoCore_global.h"
#include <QObject>

namespace ToDoC {
enum Level{
    Optional,
    Normal,
    Important
};
class TODOCORE_EXPORT ToDo : public QObject
{

    Q_OBJECT
public:
    explicit ToDo(QObject *parent = nullptr);

    ToDo(const QString &id, const QString &todo, Level necessity=Level::Optional);

    const QString &id() const;
    void setId(const QString &newId);

    void setToDo(const QString &newToDo);
    const QString &todo() const;

    Level necessity() const;
    void setNecessity(Level newNecessity);

    static QString makeId();
    static Level intToLevel(int i);
    static int levelToInt(Level l);

private:
    QString mId;
    QString mToDo;
    Level mNecessity;
};
}

#endif // TODO_H
