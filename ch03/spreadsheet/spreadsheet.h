#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include <QTableWidget>

class Cell;

class Spreadsheet : public QTableWidget
{
    Q_OBJECT

public:
    Spreadsheet(QWidget *parent = 0);

    QString currentLocation() const;
    QString currentFormula() const;
    void clear();
    bool readFile(const QString &fileName);
    bool writeFile(const QString &fileName);

signals:
    void modified();

private slots:
    void somethingChanged();
    
private:
    enum { MagicNumber = 0x7F51C883, RowCount = 999, ColumnCount = 26 };

    Cell *cell(int row, int column) const;
    QString text(int row, int column) const;
    QString formula(int row, int column) const;
    void setFormula(int row, int column, const QString &formula);
};

#endif  /* SPREADSHEET_H */
