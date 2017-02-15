#include <QtWidgets>

#include "spreadsheet.h"

Spreadsheet::Spreadsheet(QWidget *parent)
    : QTableWidget(parent)
{
    clear();
}

QString Spreadsheet::currentLocation() const
{
    return QChar('A' + currentColumn())
           + QString::number(currentRow() + 1);
}

QString Spreadsheet::currentFormula() const
{
    return QString("");
}

void Spreadsheet::clear()
{
    setRowCount(RowCount);
    setColumnCount(ColumnCount);

    setCurrentCell(0, 0);
}
