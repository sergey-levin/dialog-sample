#ifndef POINTERHOLDER_H
#define POINTERHOLDER_H

#include <QPointer>
#include <QWidget>

class CustomWidget;

class OptionsPage : public QObject
{
    Q_OBJECT
public:
    explicit OptionsPage(QObject *parent = nullptr);
    ~OptionsPage();

    QWidget *widget();
    void apply();
    void finish();

private:
    QPointer<CustomWidget> m_widget;
};

#endif // POINTERHOLDER_H
