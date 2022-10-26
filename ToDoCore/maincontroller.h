#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include "ToDoCore_global.h"
#include "todomodel.h"

namespace ToDoC {
class TODOCORE_EXPORT MainController
{
public:
    MainController();
    ToDoModel *model() const;

private:
    ToDoModel *mModel;
};
}

#endif // MAINCONTROLLER_H
