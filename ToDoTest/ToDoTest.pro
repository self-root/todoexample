TEMPLATE = app
QT += gui sql

CONFIG += c++11

isEmpty(CATCH_INCLUDE_DIR): CATCH_INCLUDE_DIR=$$(CATCH_INCLUDE_DIR)
!isEmpty(CATCH_INCLUDE_DIR): INCLUDEPATH *= $${CATCH_INCLUDE_DIR}

isEmpty(CATCH_INCLUDE_DIR): {
    message("CATCH_INCLUDE_DIR is not set, assuming Catch2 can be found automatically in your system")
}

SOURCES +=         tst_instance.cpp catch2/catch_amalgamated.cpp
HEADERS += catch2/catch_amalgamated.hpp


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../ToDoCore/release/ -lToDoCore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../ToDoCore/debug/ -lToDoCore
else:unix:!macx: LIBS += -L$$OUT_PWD/../ToDoCore/ -lToDoCore

INCLUDEPATH += $$PWD/../ToDoCore
DEPENDPATH += $$PWD/../ToDoCore

