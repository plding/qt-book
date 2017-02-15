#ifndef SORTDIALOG_H
#define SORTDIALOG_H

#include <QDialog>

class QGroupBox;
class QDialogButtonBox;

class SortDialog : public QDialog
{
    Q_OBJECT

public:
    SortDialog(QWidget *parent = 0);

private:
    QGroupBox *createGroupBox(const QString &title, bool hidden = false);

    QGroupBox *primaryGroupBox;
    QGroupBox *secondaryGroupBox;
    QGroupBox *tertiaryGroupBox;
    QDialogButtonBox *buttonBox;
};

#endif /* SORTDIALOG_H */
