#include "maincontroller.h"

namespace ToDoC {
MainController::MainController()
{
    mModel = new ToDoModel;
}

ToDoModel *MainController::model() const
{
    return mModel;
}
} //namespace ToDo
