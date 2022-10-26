#ifndef TODOLISTVIEW_H
#define TODOLISTVIEW_H

#include <QListView>
#include <QObject>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace ToDoC {
    class MainController;
}
QT_END_NAMESPACE


class TodoListView : public QListView
{
    Q_OBJECT
public:
    TodoListView(ToDoC::MainController *controller, QListView *parent=nullptr);
private:
    void mouseDoubleClickEvent(QMouseEvent *mouseEvent) override;
    ToDoC::MainController *mainController;
};

#endif // TODOLISTVIEW_H
