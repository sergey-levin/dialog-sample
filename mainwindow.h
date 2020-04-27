#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class SettingsDialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

private:
    SettingsDialog *m_dialog;
};

#endif // MAINWINDOW_H
