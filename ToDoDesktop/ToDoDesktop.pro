QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    todolistview.cpp

HEADERS += \
    mainwindow.h \
    todolistview.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../ToDoCore/release/ -lToDoCore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../ToDoCore/debug/ -lToDoCore
else:unix:!macx: LIBS += -L$$OUT_PWD/../ToDoCore/ -lToDoCore

INCLUDEPATH += $$PWD/../ToDoCore
DEPENDPATH += $$PWD/../ToDoCore
