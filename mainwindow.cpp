#include "mainwindow.h"
#include "settingsdialog.h"

#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_dialog(new SettingsDialog(this))
{
    QPushButton *btn = new QPushButton(tr("Show settings"), this);
    connect(btn, &QPushButton::clicked, [this] {
        m_dialog->exec();
    });
}

