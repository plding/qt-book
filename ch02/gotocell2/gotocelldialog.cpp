#include <QtWidgets>
#include "gotocelldialog.h"

GoToCellDialog::GoToCellDialog(QWidget *parent)
    : QDialog(parent)
{
    setupUi(this);

    QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}");
    lineEdit->setValidator(new QRegExpValidator(regExp, this));

    buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
}

void GoToCellDialog::on_lineEdit_textChanged()
{
    buttonBox->button(QDialogButtonBox::Ok)
             ->setEnabled(lineEdit->hasAcceptableInput());
}
