#include "optionspage.h"
#include "customwidget.h"

#include <QDebug>

OptionsPage::OptionsPage(QObject *parent) :
    QObject(parent)
{
}

OptionsPage::~OptionsPage()
{
    qDebug() << Q_FUNC_INFO;
    delete m_widget;
}

QWidget *OptionsPage::widget()
{
    if (m_widget)
      return m_widget;

    m_widget = new CustomWidget();
    return m_widget;
}

void OptionsPage::finish()
{
    qDebug() << Q_FUNC_INFO;
    delete m_widget;
}

void OptionsPage::apply()
{
    qDebug() << Q_FUNC_INFO;
    m_widget->store();
}

