#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include <QTableWidget>

class Spreadsheet : public QTableWidget
{
    Q_OBJECT

public:
    Spreadsheet(QWidget *parent = 0);
    QString currentLocation() const;
    QString currentFormula() const;
    void clear();

private:
    enum { RowCount = 999, ColumnCount = 26 };
};

#endif /* SPREADSHEET_H */
