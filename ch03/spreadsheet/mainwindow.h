#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class Spreadsheet;
class QLabel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

private slots:
    void updateStatusBar();

private:
    void createActions();
    void createMenus();
    void createContextMenus();
    void createToolBars();
    void createStatusBar();

    Spreadsheet *spreadsheet;
    QLabel *locationLabel;
    QLabel *formulaLabel;

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *selectSubMenu;
    QMenu *toolsMenu;
    QMenu *optionsMenu;
    QMenu *helpMenu;

    QToolBar *fileToolBar;
    QToolBar *editToolBar;

    QAction *newAction;
    QAction *openAction;
    QAction *saveAction;
    QAction *saveAsAction;
    QAction *exitAction;
    QAction *cutAction;
    QAction *copyAction;
    QAction *pasteAction;
    QAction *deleteAction;
    QAction *selectRowAction;
    QAction *selectColumnAction;
    QAction *selectAllAction;
    QAction *findAction;
    QAction *goToCellAction;
    QAction *recalculateAction;
    QAction *sortAction;
    QAction *showGridAction;
    QAction *autoRecalcAction;
    QAction *aboutAction;
    QAction *aboutQtAction;
};

#endif /* MAINWINDOW_H */
