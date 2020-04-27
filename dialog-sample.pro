QT       += core gui widgets

# Uncomment this to eliminate crash during pressing Apply button then fast press Esc key
#DEFINES += NO_CRASH

TARGET = double-delete-test
TEMPLATE = app

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    settingsdialog.cpp \
    optionspage.cpp \
    customwidget.cpp

HEADERS += \
        mainwindow.h \
    settingsdialog.h \
    optionspage.h \
    customwidget.h

OTHER_FILES += \
    test.sh \
    README.md

# Copy test.sh to app execution folder
copydata.commands = $(COPY_DIR) $$PWD/test.sh $$OUT_PWD
first.depends = $(first) copydata
export(first.depends)
export(copydata.commands)
QMAKE_EXTRA_TARGETS += first copydata
