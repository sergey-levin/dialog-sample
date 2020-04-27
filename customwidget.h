#ifndef CUSTOMWIDGET_H
#define CUSTOMWIDGET_H

#include <QWidget>

class CustomWidget : public QWidget
{
    Q_OBJECT
public:
    CustomWidget(QWidget *parent = nullptr);
    ~CustomWidget();

    void store();
};

#endif // CUSTOMWIDGET_H
