#ifndef FLOWCHARTSYMBOLPICKER_H
#define FLOWCHARTSYMBOLPICKER_H

#include <QDialog>
#include <QMap>

class QDialogButtonBox;
class QIcon;
class QListWidget;

class FlowChartSymbolPicker : public QDialog
{
    Q_OBJECT

public:
    FlowChartSymbolPicker(const QMap<int, QString> &symbolMap,
                          QWidget *parent = 0);

private:
    QIcon iconForSymbol(const QString &symbolName);

    QListWidget *listWidget;
    QDialogButtonBox *buttonBox;
};

#endif  /* FLOWCHARTSYMBOLPICKER_H */
