#include <QtGui>
#include "sortdialog.h"

SortDialog::SortDialog(QWidget *parent)
    : QDialog(parent)
{
    primaryGroupBox = createGroupBox(tr("&Primary Key"));
    secondaryGroupBox = createGroupBox(tr("&Secondary Key"), true);
    tertiaryGroupBox = createGroupBox(tr("&Tertiary Key"), true);

    buttonBox = new QDialogButtonBox(
            QDialogButtonBox::Ok|QDialogButtonBox::Cancel,
            Qt::Vertical);

    QPushButton *moreButton = buttonBox->addButton(
            tr("&More"), QDialogButtonBox::ActionRole);
    moreButton->setCheckable(true);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
    connect(moreButton, SIGNAL(toggled(bool)),
            secondaryGroupBox, SLOT(setVisible(bool)));
    connect(moreButton, SIGNAL(toggled(bool)),
            tertiaryGroupBox, SLOT(setVisible(bool)));

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(primaryGroupBox, 0, 0, 1, 1);
    mainLayout->addWidget(buttonBox, 0, 1, 1, 1);
    mainLayout->addWidget(secondaryGroupBox, 1, 0, 1, 1);
    mainLayout->addWidget(tertiaryGroupBox, 2, 0, 1, 1);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(mainLayout);

    setWindowTitle(tr("Sort"));
}

QGroupBox *SortDialog::createGroupBox(const QString &title, bool hidden)
{
    QGroupBox *groupBox = new QGroupBox(title);

    QLabel *columnLabel = new QLabel(tr("Column:"));
    QLabel *orderLabel = new QLabel(tr("Order:"));
    QComboBox *columnCombo = new QComboBox;
    QComboBox *orderCombo = new QComboBox;

    QStringList columns;
    columnCombo->addItems(columns << "C" << "D" << "E" << "F");

    QStringList orders;
    orderCombo->addItems(orders << "Ascending" << "Descending");

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(columnLabel, 0, 0, 1, 1);
    layout->addWidget(columnCombo, 0, 1, 1, 1);
    layout->addWidget(orderLabel, 1, 0, 1, 1);
    layout->addWidget(orderCombo, 1, 1, 1, 2);

    groupBox->setLayout(layout);

    if (hidden) {
        groupBox->hide();
    }

    return groupBox;
}
