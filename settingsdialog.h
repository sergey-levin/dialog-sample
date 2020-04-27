#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>

class OptionsPage;

class SettingsDialog : public QDialog
{
public:
    explicit SettingsDialog(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::Dialog);

private:

    void accept() final;
    void reject() final;

    void apply();

    const QList<OptionsPage *> m_pages;
    bool m_applying { false };
};

#endif // SETTINGSDIALOG_H
