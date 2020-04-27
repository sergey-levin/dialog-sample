#include "customwidget.h"

#include <QProcess>
#include <QApplication>
#include <QEventLoop>

#include <QDebug>

CustomWidget::CustomWidget(QWidget *parent):
    QWidget(parent)
{
}

CustomWidget::~CustomWidget()
{
    qDebug() << Q_FUNC_INFO;
}

void CustomWidget::store()
{
    // Time consuming operation with event loop
    QEventLoop *loop = new QEventLoop(this);

    QProcess *process = new QProcess;
    process->setProgram("./test.sh");

    QObject::connect(process, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), qApp,
                     [=](int exitCode, QProcess::ExitStatus exitStatus) {
        qDebug() << "State:" << exitCode << exitStatus;

        if (loop)
            loop->quit();
    });

    process->start();

    loop->exec();
    delete loop, loop = 0;
}
