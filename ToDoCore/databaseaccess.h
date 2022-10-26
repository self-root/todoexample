#ifndef DATABASEACCESS_H
#define DATABASEACCESS_H

#include "ToDoCore_global.h"
#include "tododao.h"

#include <QObject>

class QSqlDatabase;


namespace ToDoC {
class TODOCORE_EXPORT DatabaseAccess : public QObject
{
    Q_OBJECT
protected:
    explicit DatabaseAccess(QObject *parent = nullptr);

private:
    QSqlDatabase *mDatabase;

public:
    static DatabaseAccess *instance_;
    ToDoDao *mTodoDao;

    static DatabaseAccess *dbAccessInstance();
};
}


#endif // DATABASEACCESS_H
