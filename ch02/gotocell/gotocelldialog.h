#ifndef GOTOCELLDIALOG_H
#define GOTOCELLDIALOG_H

#include <QDialog>

class QLabel;
class QLineEdit;
class QDialogButtonBox;

class GoToCellDialog : public QDialog
{
    Q_OBJECT

public:
    GoToCellDialog(QWidget *parent = 0);

private slots:
    void enableOkButton();

private:
    QLabel *label;
    QLineEdit *lineEdit;
    QDialogButtonBox *buttonBox;
};

#endif  /* GOTOCELLDIALOG_H */
