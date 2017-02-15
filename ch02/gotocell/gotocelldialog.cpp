#include <QtWidgets>
#include "gotocelldialog.h"

GoToCellDialog::GoToCellDialog(QWidget *parent)
    : QDialog(parent)
{
    label = new QLabel(tr("&Cell Location:"));
    lineEdit = new QLineEdit;
    label->setBuddy(lineEdit);

    QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}");
    lineEdit->setValidator(new QRegExpValidator(regExp, this));

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                    |QDialogButtonBox::Cancel);

    buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);

    connect(lineEdit, SIGNAL(textChanged(const QString &)),
            this, SLOT(enableOkButton()));
    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    QHBoxLayout *topLayout = new QHBoxLayout;
    topLayout->addWidget(label);
    topLayout->addWidget(lineEdit);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);

    setWindowTitle(tr("Go to Cell"));
    setFixedSize(sizeHint());
}

void GoToCellDialog::enableOkButton()
{
    buttonBox->button(QDialogButtonBox::Ok)
             ->setEnabled(lineEdit->hasAcceptableInput());
}
