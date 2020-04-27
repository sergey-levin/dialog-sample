#include "settingsdialog.h"
#include "optionspage.h"

#include <QGridLayout>
#include <QPushButton>
#include <QDialogButtonBox>

SettingsDialog::SettingsDialog(QWidget *parent, Qt::WindowFlags f):
    QDialog(parent, f),
    m_pages{ new OptionsPage }
{
    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok |
                                                       QDialogButtonBox::Apply |
                                                       QDialogButtonBox::Cancel);
    connect(buttonBox->button(QDialogButtonBox::Apply), &QAbstractButton::clicked,
            this, &SettingsDialog::apply);

    connect(buttonBox, &QDialogButtonBox::accepted, this, &SettingsDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &SettingsDialog::reject);

    auto mainGridLayout = new QGridLayout;
    mainGridLayout->addWidget(buttonBox, 2, 0, 1, 2);
    mainGridLayout->setColumnStretch(1, 4);
    setLayout(mainGridLayout);

    buttonBox->button(QDialogButtonBox::Ok)->setDefault(true);

    foreach (OptionsPage *page, m_pages)
        mainGridLayout->addWidget(page->widget());
}

void SettingsDialog::accept()
{
    if (m_applying)
        return;

    apply();
    foreach (OptionsPage *page, m_pages)
        page->finish();
    done(QDialog::Accepted);
}

void SettingsDialog::reject()
{
    if (m_applying)
        return;

    foreach (OptionsPage *page, m_pages)
        page->finish();
    done(QDialog::Rejected);
}

void SettingsDialog::apply()
{
    if (m_applying)
        return;
#ifdef NO_CRASH
    m_applying = true; // This eliminates crash during pressing Apply button then fast press Esc key
#endif
    foreach (OptionsPage *page, m_pages)
        page->apply();
    m_applying = false;
}

